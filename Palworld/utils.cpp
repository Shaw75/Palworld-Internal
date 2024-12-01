#include "utils.h"
namespace Utils
{
	void VTableHook::Initialize(void* pTarget) {
		this->pTarget = pTarget;
		this->oVTable = *(void***)pTarget;
		uint32_t size = CalcVTableSize();
		this->VTable = new void* [size];
		memcpy(VTable, oVTable, size * sizeof(void*));
		*(void***)pTarget = VTable;
	}
	uint32_t VTableHook::CalcVTableSize() {
		int i = 0;
		for (uint32_t i = 0; true; i++)
		{
			if (oVTable[i] == NULL)
				return i;
		}
		
		return 0;

	}
	void VTableHook::Bind(uint32_t index,void* Function) {
		VTable[index] = Function;
	}
	void VTableHook::UnBind(uint32_t index) {
		VTable[index] = oVTable[index];
	}
	void VTableHook::UnAllBind() {
		*(void***)pTarget = oVTable;
	}
	void Utils::StartConsole() {
		AllocConsole();
		freopen("CONOUT$","w",stdout);
	}
}