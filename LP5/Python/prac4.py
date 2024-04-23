import numpy as np
import pycuda.driver as cuda
import pycuda.autoinit
from pycuda.compiler import SourceModule

N = 1000000
block_size = 256

# CUDA kernel
mod = SourceModule("""
__global__ void vectorAddition(int *a, int *b, int *c) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < %(N)s) {
        c[tid] = a[tid] + b[tid];
    }
}
""" % {'N': N})

vectorAddition = mod.get_function("vectorAddition")

# Host arrays
a = np.arange(N).astype(np.int32)
b = np.arange(N).astype(np.int32)
c = np.zeros_like(a)

# Device arrays
a_gpu = cuda.mem_alloc(a.nbytes)
b_gpu = cuda.mem_alloc(b.nbytes)
c_gpu = cuda.mem_alloc(c.nbytes)

# Copy data to device
cuda.memcpy_htod(a_gpu, a)
cuda.memcpy_htod(b_gpu, b)

# Launch kernel
vectorAddition(a_gpu, b_gpu, c_gpu, block=(block_size, 1, 1),
               grid=((N + block_size - 1) // block_size, 1))

# Copy result back to host
cuda.memcpy_dtoh(c, c_gpu)

# Verify result
assert np.allclose(c, a + b)
print("Vector addition successful!")
