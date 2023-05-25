import java.util.*;
import javax.crypto.*;
import java.security.SecureRandom;

public class des {

    public static void main(String[] args) throws Exception {

        KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
        SecureRandom secureRandom = new SecureRandom();
        keyGenerator.init(secureRandom);
        SecretKey secretKey = keyGenerator.generateKey();

        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");

        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        String plaintext = "This is a secret message";
        byte[] plaintextBytes = plaintext.getBytes();
        byte[] encryptedBytes = cipher.doFinal(plaintextBytes);

        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);

        System.out.println("\nKey: " + Base64.getEncoder().encodeToString(secretKey.getEncoded()));
        System.out.println("\nPlaintext: " + plaintext);
        System.out.println("\nCiphertext: " + Base64.getEncoder().encodeToString(encryptedBytes));
        System.out.println("\nDecrypted ciphertext: " + decryptedText + "\n");
    }
}
  