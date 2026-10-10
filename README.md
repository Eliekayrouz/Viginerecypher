# Vigenère Cipher with Permutation

## 1. How to Compile and Run
Open your terminal in the project folder and run the following commands:

```bash
# Compile the program
g++ -o vigenere main.cpp

# Run the executable
./vigenere
```
2. Multi-Round Permutation Logic & Reversal
Encryption (P_Encrypt): After the Vigenère substitution round, the text is split into two rows based on index positions:

row1 stores characters at even indices (0, 2, 4, ...).

row2 stores characters at odd indices (1, 3, 5, ...).

The final output combines them as row1 + row2.

Decryption (P_Decrypt):

Calculates the midpoint (length + 1) / 2 to cleanly separate row1 and row2.

Weaves the two rows back together alternatingly to fully restore the original character order before running Vigenère decryption.

3. Example Test Case (End-to-End Cycle)
Input Plaintext: elie

Secret Key: andy

Encryption Workflow:
Vigenère Substitution: Transforms elie using key andy -> eylc

Permutation Round: Splits eylc into even/odd rows (row1 = "el", row2 = "yc") -> elyc

Final Ciphertext Output: elyc

Decryption Workflow:
Reverse Permutation: Takes elyc, splits it, and weaves it back -> eylc

Vigenère Decryption: Reverses the letter shifts using key andy -> elie

Final Result: Successfully restored original plaintext elie.
<img width="668" height="215" alt="image" src="https://github.com/user-attachments/assets/0e68af78-97c4-4b38-9456-151575cc4613" />
<img width="721" height="201" alt="image" src="https://github.com/user-attachments/assets/d7294bd5-24f7-472c-90ce-45b316a361d9" />


