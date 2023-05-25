import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class aes {
    public static void main(String[] args) {
        try {
            String plainText = "Hello, World!";
            String secretKey = "MySecretKey12345";

            // Encrypt the plaintext
            Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
            SecretKeySpec keySpec = new SecretKeySpec(secretKey.getBytes(), "AES");
            cipher.init(Cipher.ENCRYPT_MODE, keySpec);
            byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
            String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
            System.out.println("Encrypted Text: " + encryptedText);

            // Decrypt the ciphertext
            cipher.init(Cipher.DECRYPT_MODE, keySpec);
            byte[] decryptedBytes = cipher.doFinal(Base64.getDecoder().decode(encryptedText));
            String decryptedText = new String(decryptedBytes);
            System.out.println("Decrypted Text: " + decryptedText);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
