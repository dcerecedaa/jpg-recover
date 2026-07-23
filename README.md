# 📂 JPEG File Recovery

![C](https://img.shields.io/badge/Language-C-00599C.svg)
![Memory Management](https://img.shields.io/badge/Focus-Memory%20Management-4E6E81.svg)
![Binary Data](https://img.shields.io/badge/Data-card.raw-2E4F4F.svg)
![Harvard CS50](https://img.shields.io/badge/Course-CS50%20Harvard-A51C30.svg)

A C implementation of the **JPEG File Recovery** challenge from **Harvard University's CS50: Introduction to Computer Science**.

This project demonstrates low-level programming concepts by recovering deleted JPEG images from a raw memory card image using binary file analysis and file system principles.

---

# 📖 Overview

The objective of this challenge is to recover deleted JPEG images from a storage device.

CS50 provides a binary file named `card.raw`, which represents a bit-for-bit image of a real memory card. Although the image files are no longer visible in the file system, their binary data still exists on the storage medium.

The program scans the raw data, detects JPEG signatures, and reconstructs each image as an individual file.

---

# 🎯 Learning Objectives

This project focuses on several fundamental Computer Science concepts:

- Binary file processing
- Memory management in C
- File I/O using pointers
- File signature detection
- Low-level storage organization
- State management during sequential data processing

---

# 🛠️ Technical Concepts

## JPEG Signature Detection

JPEG files always begin with the following byte sequence:

```text
0xff 0xd8 0xff
```

The program inspects every 512-byte block and identifies the beginning of a new image by checking for this signature.

---

## Memory Management

The implementation uses standard C file pointers (`FILE *`) to efficiently manage:

- Reading from the raw memory image
- Creating output files
- Writing binary data
- Properly opening and closing files during execution

---

## Block-Based Processing

Memory cards using FAT file systems store data in fixed-size blocks.

The program reads the input file in **512-byte blocks**, matching the physical storage layout and avoiding unnecessary memory usage.

---

## State Management

During execution, the program keeps track of whether a JPEG file is currently being written.

When a new JPEG signature is detected:

- The current output file is closed (if one is open)
- A new JPEG file is created
- Subsequent blocks are written until another JPEG header is found

---

# 🚀 How It Works

1. Open the `card.raw` file.
2. Read the file sequentially in **512-byte blocks**.
3. Check each block for a valid JPEG header.
4. When a new header is found:
   - Close the current image (if applicable)
   - Create a new file named `###.jpg`
5. Continue writing blocks until another JPEG header is detected.
6. Repeat until reaching the end of the memory image.

The program successfully reconstructs **50 JPEG images**, all of which can be opened normally after recovery.

---

# 📂 Project Structure

```text
recover/
├── card.raw          # Raw memory card image provided by CS50
├── recover.c         # JPEG recovery implementation
└── README.md
```

---

# ⚙️ Build & Run

## Compile

```bash
gcc recover.c -o recover
```

## Execute

```bash
./recover card.raw
```

Recovered images will be generated in the current directory:

```text
000.jpg
001.jpg
002.jpg
...
049.jpg
```

---

# 💡 Implementation Details

The solution relies on:

- Sequential binary file reading
- Header-based file identification
- Dynamic file creation
- Binary data writing
- Efficient memory usage without loading the entire file into RAM

The implementation runs in **linear time O(n)**, scanning the memory image only once.

---

# 📦 Resources

| File | Description |
|------|-------------|
| `card.raw` | Raw memory card image supplied by CS50 |
| `recover.c` | Source code implementing the recovery algorithm |

---

# 🛠️ Technologies

- C
- Standard Library (`stdio.h`)
- Standard Library (`stdlib.h`)
- Fixed-width Integer Types (`stdint.h`)

---

# 🎓 About the Challenge

This project is based on one of the programming assignments from **Harvard University's CS50: Introduction to Computer Science**.

Its purpose is to introduce students to:

- Binary data manipulation
- Low-level file systems
- Pointer-based programming
- Efficient memory handling
- File I/O in C

---

# 🤝 Contributing

Suggestions, improvements, and bug reports are always welcome.

Feel free to open an issue or submit a pull request.

---

# 👨‍💻 Author

**David Cereceda Pérez**

- GitHub: https://github.com/dcerecedaa
- LinkedIn: https://linkedin.com/in/david-cereceda-perez-3ba0962b6

---

> **Acknowledgment**
>
> This project was completed as part of **Harvard University's CS50: Introduction to Computer Science** course. The recovery algorithm was implemented independently based on the challenge requirements and is intended for educational and portfolio purposes.
