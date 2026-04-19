# НотПетя/Nyetya/ NotPetya 2.0.1

## Overview

This repository contains a decompiled analysis of the NotPetya file encryption routine, reconstructed from observed binaries. The focus is on execution flow and destructive file-handling behavior.

---

## Core Execution Flow

```
main()
 ├── init_environment()
 ├── enumerate_drives()
 ├── scan_filesystem()
 ├── select_targets()
 ├── process_files()
 └── finalize_changes()
```

---

## Key Components

### Initialization

Handles system preparation and execution setup.

```c
void init_environment() {
    acquire_privileges();
    prepare_runtime_state();
}
```

---

### File Traversal

Recursive scanning of mounted volumes.

```c
void scan_files(char *path) {
    for (entry in directory(path)) {
        if (is_directory(entry))
            scan_files(entry);

        if (is_target(entry))
            queue(entry);
    }
}
```

---

### File Processing Logic

Core transformation routine applied to selected files.

```c
void process_file(file_t *f) {
    buffer = read(f);
    transform(buffer);
    write(f, buffer);
}
```

---

## Transformation Behavior (High Level)

- Reads file contents into memory buffer  
- Applies deterministic byte-level transformation  
- Writes modified data back to disk  
- Overwrites original structure integrity  

---

## Target Selection Logic

Typical filters observed:

- User documents  
- Archives  
- Database files  
- Media and backup files  

System binaries are generally avoided in early traversal stages.

---

## Execution Characteristics

- Recursive filesystem traversal  
- Multi-threaded file processing  
- Deterministic transformation pattern  
- No reliable recovery path observed in real-world samples  

---

## Summary

This module represents the file encryption / destruction subsystem extracted from NotPetya-related binaries. It demonstrates a structured file traversal engine combined with irreversible data modification logic.

---
