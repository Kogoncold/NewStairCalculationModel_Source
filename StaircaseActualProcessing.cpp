//Staircase��¥�ݣ�
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <thread>

#include "Parameters_Material.h"
#include "Parameters_Volume.h"
#include "Miscellaneous.h"

std::int_fast32_t VolumeTransition() {
	std::ofstream Parameters_Volume;//���ع��ɲ������������
	Parameters_Volume.open("Material_Settings.txt", std::ios::out);//�򿪲��������ļ�
	Volume_Transition VolumeTransition;
	std::cout << "����������ɲ㳤�ȡ���ȡ��߶ȣ���λ��cm����" << std::endl;
	std::cin >> VolumeTransition.Material_Length >> VolumeTransition.Material_Width >> VolumeTransition.Material_Heigh;//���������
	double Volume = VolumeTransition.Material_Length * VolumeTransition.Material_Width * VolumeTransition.Material_Heigh;//�������
	Parameters_Volume << "���ɲ㳤�ȣ�" << VolumeTransition.Material_Length << "cm\n"  //���ɲ㳤������
		<< "���ɲ��ȣ�" << VolumeTransition.Material_Width << "cm\n" //���ɲ�������
		<< "���ɲ㳤�ȣ�" << VolumeTransition.Material_Heigh << "cm\n"//���ɲ㳤������
	<< "���ɲ������" <<  Volume << "cm3" ;//���ɲ����
	Parameters_Volume.close();//�رղ��������ļ�
	return EXIT_SUCCESS;
}
std::int_fast32_t MaterialTransition() {

}
std::int_fast32_t main(std::int_fast32_t argc, std::int_fast8_t* argv[]) {
	std::cout << "��ѡ��׼������Ĳ��֣�\n1.���ɲ㳤�ȡ���ȡ��߶�\n";
	std::cin >> PartialSelection;
	if (PartialSelection==1) {
		std::thread Volume_Transition(VolumeTransition);//���ɲ����
		Volume_Transition.join();
	}
	else if (PartialSelection == 2) {
		std::thread Material_Transition(MaterialTransition);//���ɲ����
		Volume_Transition.join();
	}
	system("pause");
	return EXIT_SUCCESS;
}
/*
1.ѡ����ɲ����
2.ѡ����ɲ㽨��
3.ѡ��¥�����
4.ѡ��¥�ݽ���
*/