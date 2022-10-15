//
// Created by keyuan on 2022/10/14.
//

#include <cstdio>

namespace Gospel::Compiler
{
    typedef unsigned long DWORD;
    typedef unsigned short WORD;
    typedef unsigned char BYTE;
#define IMAGE_SIZEOF_SHORT_NAME 8
#define CST_FUNC 0x20
#define CST_NOTFUNC 0

    typedef struct IMAGE_FILE_HEADER
    {
        WORD Machine;
        WORD NumberOfSections;
        DWORD TimeDateStamp;
        DWORD PointerToSymbolTable;
        DWORD NumberOfSymbols;
        WORD SizeOfOptionalHeader;
        WORD Characteristics;

    }IMAGE_FILE_HEADER,* POINTER_IMAGE_FILE_HEADER;


    typedef struct IMAGE_SECTION_HEADER
    {
        BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
        union
        {
            DWORD PhysicalAddress;
            DWORD VirtualSize;
        }Misc;
        DWORD VirtualAddress;
        DWORD SizeOfRawData;
        DWORD PointerToRawData;
        DWORD PointerToRelocations;
        DWORD PointerToLineNumbers;
        WORD NumberOfRelocations;
        WORD NumberOfLineNumbers;
        DWORD Characteristics;
    }IMAGE_SECTION_HEADER,* Pointer_IMAGE_SECTION_HEADER;

    typedef struct IMAGE_SYMBOL
    {
        union
        {
            BYTE ShortName[8];
            struct
            {
                DWORD Short;
                DWORD Long;
            }Name;
            BYTE * LongName[2];
        }N;
        DWORD Value;
        short SectionNumber;
        WORD Type;
        BYTE StorageClass;
        BYTE NumberOfAuxSymbols;
    }IMAGE_SYMBOL;

    typedef struct CoffSym
    {
        DWORD Name;
        DWORD Next;
        DWORD Value;
        short SectionNumber;
        WORD Type;
        BYTE StorageClass;
        BYTE NumberOfAuxSymbols;
    }CoffSym;

    typedef struct IMAGE_RELOCATION
    {
        union
        {
            DWORD VirtualAddress;
            DWORD RelocCount;
        };
        DWORD SymbolTableIndex;
        WORD Type;
    }IMAGE_RELOCATION;

    typedef struct CoffReloc
    {
        DWORD offset;
        DWORD cfsym;
        BYTE section;
        BYTE type;
    }CoffReloc;

    typedef struct Section
    {
        int data_offset;
        char * data;
        int data_allocated;
        char index;
        struct Section* link;
        int* hashtab;
    } Section;

}