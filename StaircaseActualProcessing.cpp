//Staircase（楼梯）
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
	std::ofstream Parameters_Volume;//记载过渡层体积参数的流
	Parameters_Volume.open("Material_Settings.txt", std::ios::out);//打开材料设置文件
	Volume_Transition VolumeTransition;
	std::cout << "请逐步输入过渡层长度、宽度、高度（单位：cm）：" << std::endl;
	std::cin >> VolumeTransition.Material_Length >> VolumeTransition.Material_Width >> VolumeTransition.Material_Heigh;//长宽高输入
	double Volume = VolumeTransition.Material_Length * VolumeTransition.Material_Width * VolumeTransition.Material_Heigh;//体积运算
	Parameters_Volume << "过渡层长度：" << VolumeTransition.Material_Length << "cm\n"  //过渡层长度输入
		<< "过渡层宽度：" << VolumeTransition.Material_Width << "cm\n" //过渡层宽度输入
		<< "过渡层长度：" << VolumeTransition.Material_Heigh << "cm\n"//过渡层长度输入
	<< "过渡层体积：" <<  Volume << "cm3" ;//过渡层体积
	Parameters_Volume.close();//关闭材料设置文件
	return EXIT_SUCCESS;
}
std::int_fast32_t MaterialTransition() {

}
std::int_fast32_t main(std::int_fast32_t argc, std::int_fast8_t* argv[]) {
	std::cout << "请选择准备输入的部分：\n1.过渡层长度、宽度、高度\n";
	std::cin >> PartialSelection;
	if (PartialSelection==1) {
		std::thread Volume_Transition(VolumeTransition);//过渡层体积
		Volume_Transition.join();
	}
	else if (PartialSelection == 2) {
		std::thread Material_Transition(MaterialTransition);//过渡层体积
		Volume_Transition.join();
	}
	system("pause");
	return EXIT_SUCCESS;
}
/*
1.选择过渡层体积
2.选择过渡层建材
3.选择楼梯体积
4.选择楼梯建材
*/