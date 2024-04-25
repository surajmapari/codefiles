#include <iostream>
#include <cuda_runtime.h>

const int N = 1000000;

__global__ void vectorAddition(int *a, int *b, int *c) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < N) {
        c[tid] = a[tid] + b[tid];
    }
}

int main() {
    int *a, *b, *c;
    int *d_a, *d_b, *d_c;
    int size = N * sizeof(int);

    // Allocate memory on host
    a = (int*)malloc(size);
    b = (int*)malloc(size);
    c = (int*)malloc(size);

    // Initialize vectors
    for (int i = 0; i < N; ++i) {
        a[i] = i;
        b[i] = i;
    }

    // Allocate memory on device
    cudaMalloc(&d_a, size);
    cudaMalloc(&d_b, size);
    cudaMalloc(&d_c, size);

    // Copy vectors from host to device
    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

    // Perform vector addition on device
    int blockSize = 256;
    int numBlocks = (N + blockSize - 1) / blockSize;
    vectorAddition<<<numBlocks, blockSize>>>(d_a, d_b, d_c);

    // Copy result back to host
    cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    // Verify result
    bool success = true;
    for (int i = 0; i < N; ++i) {
        if (c[i] != 2 * i) {
            success = false;
            break;
        }
    }

    if (success) {
        std::cout << "Vector addition successful!" << std::endl;
    } else {
        std::cout << "Vector addition failed!" << std::endl;
    }

    // Free host memory
    free(a);
    free(b);
    free(c);

    return 0;
}
