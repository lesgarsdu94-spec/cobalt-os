# 🌌 NovaTech Cobalt OS (Codename: Cobalt) 🚀

Welcome to the official repository for **NovaTech Cobalt OS**, engineered by **NovaTech Systems Corp.** 💻 Cobalt is an educational, hobbyist operating system built to replicate the clean, architectural minimalism of early UNIX systems (circa April 1971) on modern x86 hardware.

🤖 **Mobile-First Development:** Because this project is developed entirely on an Android device without a local terminal environment, compiling, assembling, and linking are handled 100% in the cloud using **GitHub Actions**.

---

## 🛠️ System Specification & Architecture

* **💿 Version Target:** `v0.01` (April 1971 Specification)
* **🏷️ Active Codename:** `Cobalt` (Valid for builds v0.01 through v0.89)
* **🖥️ Platform Target:** x86 (32-bit `i686-elf` architecture)
* **🎯 Boot Loader:** Multiboot v1 Compliant (GRUB/QEMU compatible)
* **🧰 Core Languages:** C (GNU99 freestanding) & Assembly (NASM)

---

## 📂 System File Placement & Topology

Version 0.01 features a hierarchical, read-only RAM disk embedded directly inside the kernel's memory space. It maps out the exact directory layout utilized by the earliest research versions of UNIX:

```text
📂 / (Root System Directory)
├── 📂 bin/
│   ├── ⚙️ ls        # System Builtin: Lists global or local directory maps
│   └── ⚙️ cat       # System Builtin: Displays specific file contents
├── 📂 etc/
│   └── 📄 motd      # Configuration: Holds the "Message of the Day"
└── 📂 usr/
    └── 📄 author    # Documentation: Credits the NovaTech development team
