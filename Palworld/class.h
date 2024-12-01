#pragma once
#include "base.h"

struct FNameEntryHeader
{
	uint16_t bIsWide : 1;
	uint16_t LowercaseProbeHash : 5;
	uint16_t Len : 10;
};

struct FNameEntry {

	FNameEntryHeader Header;
	union
	{
		char AnsiName[1024];
		char WideName[1024];

	};
};

struct FNamePool {
	char pad_000[0x10];
	uint8_t* Blocks[8192]; //字符串数组，重中之重
	static FNamePool* GetFNamePool();

};
class  UObject {
public:

	std::string GetName();
	static std::string GetName(uint32_t NameID);




};