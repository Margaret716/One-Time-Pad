# One Time Pad

 <br />
 
One-time pad (OTP) is a encryption technique that uses randomly generated keys of the same length as the original message. The key is used only once and should never be reused.

The process of OTP encryption involves performing the XOR (exclusive OR) logical operation between each bit of the message to be encrypted and the corresponding bit in the key. The result of this operation is the encrypted bit. This process is repeated for each bit in the message.

It is important for the key to be truly random and for secure key storage to be maintained. The recipient must have an identical key to decode the encrypted message. Decryption is done by performing the XOR operation between the encrypted message and the corresponding bit in the key.

The main advantage of OTP encryption is that it is theoretically unbreakable, provided that the key is truly random, never reused, and securely stored. However, OTP has practical limitations, such as the need for prior key agreement between the sender and recipient, as well as the requirement for secure key exchange.

<br />

## Example of OTP Encryption

 <br />

Let's assume we have a message to encrypt: "HELLO" and a randomly generated key of the same length: "QIVRS".

Convert each letter of the message to its ASCII numbers (e.g., A=65, B=66, C=67, ...). In our case, "HELLO" converts to "72-69-76-76-79" and "QIVRS" to "81-73-86-82-83". Now convert each numbers to the binary system.

HELLO  ->  72-69-76-76-79  ->  1001000-1000101-1001100-1001100-1001111
<br />
QIVRS  ->  81-73-86-82-83  ->  1010001-1001001-1010110-1010010-1010011

Perform the XOR operation between each number of the message and its corresponding number in the key. For example:

First number: 1001000 XOR 1010001 = 0011001
Second number: 1000101 XOR 1001001 = 0001100
Third number: 1001100 XOR 1010110 = 0011010
Fourth number: 1001100 XOR 1010010 = 0011110
Fifth number: 1001111 XOR 1010011 = 0011100

Convert the encrypted numbers back to their ASCII numbers and then characters. In our case, "25-12-26-30-28" converts to "EM-FF-SUB-RS-FS".

We obtain the encrypted message "EM-FF-SUB-RS-FS". The recipient, having an identical key, can decode the message by performing the XOR operation between the encrypted message and the key.

It is important for the key to never be reused and to be stored securely to maintain encryption security.
