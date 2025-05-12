# 📬 Minitalk

> A 42-school project focused on interprocess communication (IPC) using Unix signals — an exercise in bit-level messaging between processes.

---

## 📌 Overview

**Minitalk** is a project where you must create a **client-server** communication system using **only UNIX signals**: `SIGUSR1` and `SIGUSR2`.  
The client encodes a message in binary and sends it **bit by bit** to the server.  
The server decodes these bits and prints the original message.

This project emphasizes low-level systems programming, bit manipulation, and signal handling in UNIX.

---

## 🛠️ Features

✅ Interprocess communication with signals  
✅ Bit-by-bit message encoding  
✅ Custom signal handler  
✅ Client acknowledgment feature  
✅ Handles long messages and newlines  
✅ Norm-compliant and modular

---

## 📦 Project Structure

```bash
minitalk/
├── Makefile
├── client.c
├── server.c
├── utils.c
├── includes/
│   └── minitalk.h
```

---

## 🔧 Compilation

Use the `Makefile` to compile the project:

```bash
make        # Compiles server and client
make clean  # Removes object files
make fclean # Cleans all binaries
make re     # Recompiles everything
```

---

## 🚀 Usage

### 1. Start the server

```bash
./server
```

Output:

```
[🟢] Server PID: 12345
```

### 2. Send a message from the client

```bash
./client <server_pid> "Your message here"
```

Example:

```bash
./client 12345 "Hello from the client!"
```

---

## 🔄 How It Works

- The client sends each character **bit by bit**, using:
  - `SIGUSR1` to represent binary `0`
  - `SIGUSR2` to represent binary `1`
- The server reconstructs the character and prints the message.
- The server can send acknowledgments (bonus).

---

## 🧪 Bonus Features (Optional)

> Implemented in `bonus/` folder

- 📨 Acknowledgment signal from server to client
- 🧵 Multithreaded-safe printing
- 🕒 Timeout protection for client
- 💬 Support for Unicode / special characters

---

## 🧼 Code Style

- Norm-compliant (42 style)
- Modular source files
- Robust error handling
- Clean signal-safe code

---

## ⚠️ Edge Cases Handled

- Invalid PID or unreachable server
- Very large messages
- Rapid-fire signal control
- Unexpected server/client crash

---

## 🧑‍💻 Author

Made with 💙 by [Your Name]  
Feel free to connect on [LinkedIn](https://www.linkedin.com) or check out more of my projects!

---

## 📚 References

- [UNIX Signals - Signal(7)](https://man7.org/linux/man-pages/man7/signal.7.html)
- [Kill(2) - Sending Signals](https://man7.org/linux/man-pages/man2/kill.2.html)

---
