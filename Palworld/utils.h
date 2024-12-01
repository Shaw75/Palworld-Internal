#pragma once
#include "base.h"
namespace Utils
{
	class VTableHook {
	public:
		  void Initialize(void* pTarget);
		  //hook�����ָ��index�ĺ���
		  void Bind(uint32_t index, void* Function);
		  //ж��hook
		  void UnBind(uint32_t index);

		  //ж��ȫ��hook
		  void UnAllBind();

		  //��ȡ����ԭʼ����ָ��
		  template <typename T>
		  T GetOriginal(uint32_t index) {
			  return (T)oVTable[index];
		  }
		  

	private:
		uint32_t CalcVTableSize();
		void* pTarget = NULL; 
		void** VTable = NULL; //ָ���޸ĺ�����
		void** oVTable = NULL;//ָ��ԭʼ���

	};
	void StartConsole();





}