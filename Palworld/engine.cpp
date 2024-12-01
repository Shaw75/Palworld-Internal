#include "engine.h"

namespace  Engine
{   
	HWND hWnd = NULL;
	//HMODULE hModule = NULL;
	void Engine::Initialaze() {
	
		hWnd = FindWindowW(L"UnrealWindow", NULL);
	

	}
	HWND GethWnd() {
		return hWnd;
	}
	IDXGISwapChain* Engine::GetSwapChain() {
		
		//"Palworld-Win64-Shipping.exe"+08341B10
		uint8_t* hModule = *(uint8_t**)((uint8_t*)GetModuleHandleA(NULL) + 0x08341B10);
		uint8_t* GameRender1 = *(uint8_t**)((uint8_t*)hModule + 0x50);
		uint8_t* GameRender2 = *(uint8_t**)((uint8_t*)GameRender1 + 0x20);
		uint8_t* GameRender3 = *(uint8_t**)((uint8_t*)GameRender2 + 0x138);
		return *(IDXGISwapChain**)(GameRender3+0x130);

	}
	 

}