#pragma once
#include "base.h"
namespace Utils
{
	class VTableHook {
	public:
		  void Initialize(void* pTarget);
		  //hook虚表上指定index的函数
		  void Bind(uint32_t index, void* Function);
		  //卸载hook
		  void UnBind(uint32_t index);

		  //卸载全部hook
		  void UnAllBind();

		  //获取表上原始函数指针
		  template <typename T>
		  T GetOriginal(uint32_t index) {
			  return (T)oVTable[index];
		  }
		  

	private:
		uint32_t CalcVTableSize();
		void* pTarget = NULL; 
		void** VTable = NULL; //指向修改后的虚表
		void** oVTable = NULL;//指向原始虚表

	};
	void StartConsole();





}