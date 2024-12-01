#include "class.h"
#include "engine.h"
FNamePool* FNamePool::GetFNamePool() {

	void* GName = NULL;
	if (!GName) 
	{
		GName = (uint8_t*)GetModuleHandleA(NULL)+0x8913480;

	}
	return (FNamePool*)GName;
}
std::string UObject::GetName() {
	 
	return GetName(*(uint32_t*)(uint8_t*)this+0x18);// UObject有5个成员
	/*
	EObjectFlags					ObjectFlags;   //4
	int32							InternalIndex;  //4
	UClass* ClassPrivate;  //8
	FName							NamePrivate;  //加一个虚表8字节正好0x18
	*/
}

std::string UObject::GetName(uint32_t NameID) 
{
	uint32_t Block = NameID >> 16;
	uint32_t Offset = NameID & 65535;
	FNamePool* NamePool = FNamePool::GetFNamePool();
	FNameEntry* NameEntry = (FNameEntry*)(NamePool->Blocks[Block] + 2 * Offset);
	if (NameEntry->Header.bIsWide) return std::string("WString");
	return std::string(NameEntry->AnsiName,NameEntry->Header.Len );
}