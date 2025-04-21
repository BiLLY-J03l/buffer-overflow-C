![image](https://github.com/user-attachments/assets/745fbc2f-cf89-42e1-861b-40e664b18add)# buffer-overflow-C
This repo showcases how to exploit a buffer overflow bug in C code


- buffer overflow is a very dangerous bug that is exploited everyday in modern programs.
- secure.c uses a very dangerous function which is the gets() functions.
- gets() function doesn't check for buffer limits which allows buffer overflows.

- looking at the source code, it's impossible to get the correct password. 
- ![image](https://github.com/user-attachments/assets/06e7c84c-f5c1-40ca-bb60-febf24b6f290)
- so, we take the other route which is exploiting buffer overflow.
- we compile the program with ignoring the gets() warnings.
- ![image](https://github.com/user-attachments/assets/8ae893f2-bc21-496f-9742-123247daab19)

- We run the program
- ![image](https://github.com/user-attachments/assets/4b648cd0-ef79-45dd-a256-9b458a25159b)
  - we get a segmentation fault.
  - the segfault happens on 47464646.
  - using python3 to convert that to string.
  - we find that the buffer overflows at 'GFFF' and since that's little endian that means 'FFFG'
  - ![image](https://github.com/user-attachments/assets/51b82ca1-891f-4d95-8a97-98491463b944)

- now we have the essential payload, next step is finding the address of the debug() and pass it after the payload to be pointed to by the instruction pointer.

- first we disassemble the binary with objdump or GDB
  - ![image](https://github.com/user-attachments/assets/cee119a4-31b7-4124-a16b-3faf6ddcc9ec)
  - 0x08049196 -> debug() function address

- secondly, we add the payload which is the debug() function with reversing the payload because of little endian arch
- ![image](https://github.com/user-attachments/assets/28da9ac3-48b5-4247-bd2d-882754a6c8ef)

- we use sys.stdout.buffer[payload] instead of print(payload) because print() encodes anything as a string and we want to do it in binary which is accomplished with the first one.
- run the exploit
- ![image](https://github.com/user-attachments/assets/afc375f3-fb2c-4a10-b422-777004d962b7)
- and bingo, you enter debug mode but the program exits.
- the solution to that is keeping our file descriptor open, which we can achieve with using cat.
- ![image](https://github.com/user-attachments/assets/135fdb78-063f-45c6-9007-2c3d15c32209)
- we bypassed user authentication, which highlights how dangerous buffer overflow bugs are.
