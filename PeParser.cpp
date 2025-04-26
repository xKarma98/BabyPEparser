#include <iostream>
#include <fstream>
#include <windows.h>

/*
* // We will use this struct and call 3 members.
//typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
//    WORD   e_magic;                     // Magic number
//    WORD   e_cblp;                      // Bytes on last page of file
//    WORD   e_cp;                        // Pages in file
//    WORD   e_crlc;                      // Relocations
//    WORD   e_cparhdr;                   // Size of header in paragraphs
//    WORD   e_minalloc;                  // Minimum extra paragraphs needed
//    WORD   e_maxalloc;                  // Maximum extra paragraphs needed
//    WORD   e_ss;                        // Initial (relative) SS value
//    WORD   e_sp;                        // Initial SP value
//    WORD   e_csum;                      // Checksum
//    WORD   e_ip;                        // Initial IP value
//    WORD   e_cs;                        // Initial (relative) CS value
//    WORD   e_lfarlc;                    // File address of relocation table
//    WORD   e_ovno;                      // Overlay number
//    WORD   e_res[4];                    // Reserved words
//    WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
//    WORD   e_oeminfo;                   // OEM information; e_oemid specific
//    WORD   e_res2[10];                  // Reserved words
//    LONG   e_lfanew;                    // File address of new exe header
 // } IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;
  */

int main(int argc, char* argv[]) { // Place these function parameters.
	// To handle arguments via the command line.
	if (argc != 2) {
		std::cerr << "usage is: " << argv[0] << " <PE FILE PATH>";
		return 1;
	}

	// Parse in binary mode.
	// https://en.cppreference.com/w/cpp/io/basic_ifstream - Ctrl + f "Read" we can read data blocks in binary mode.
	std::ifstream peFile(argv[1], std::ios::binary);

	// Struct pointer to access members.
	IMAGE_DOS_HEADER PIMAGE_DOS_HEADER;

	// variable read in binary mode -> Reintrepret_cast char pointer it Converts between types by reinterpreting the underlying bit pattern, we then add the size of it.
	peFile.read(reinterpret_cast<char*>(&PIMAGE_DOS_HEADER), sizeof(PIMAGE_DOS_HEADER));

	// PE magic number.
	std::cout << "The file's magic number is: 0x" << std::hex << PIMAGE_DOS_HEADER.e_magic;

	// File address of new header.
	std::cout << "The file address of the new exe header: 0x" << std::hex << PIMAGE_DOS_HEADER.e_lfanew;

	// SP value
	std::cout << "The file's SP value is: 0x" << std::hex << PIMAGE_DOS_HEADER.e_sp;

	// Relocations in the PE file
	std::cout << "File relocations: 0x" << std::hex << PIMAGE_DOS_HEADER.e_crlc;
}
