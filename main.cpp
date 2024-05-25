﻿#include<iostream>
#include<libssh/libssh.h>
#include<vector>
#include"Login.h"
#include"Padding.h"
#include<stdio.h>
#include<string>
#include"database/db.h"
#include"scan/portScan.h"	
#include"utils_scan.h"



int main()
{
	//测试SQLite POC数据库
	//POC_db();

	char cwd[10000];
	if (getcwd(cwd, sizeof(cwd)) != nullptr) {
		std::cout << "Current working directory: " << cwd << std::endl;
	}
	else {
		std::cerr << "Error getting current working directory" << std::endl;
	}

	//测试端口扫描
	//std::string outputPath = performPortScan("192.168.183.200");

	std::vector<ScanHostResult> scan_host_result = parseXmlFile("../../output_nmap/output_192.168.183.200_2024-05-25_23_07_52.xml");

	std::cout << "wait.." << endl;

	//system("pause");
	return 0;
}












//std::string exec(const char* cmd) {
//    char buffer[128];
//    std::string result = "";
//    file* pipe = _popen(cmd, "r");
//    if (!pipe) throw std::runtime_error("popen() failed!");
//    try {
//        while (fgets(buffer, sizeof(buffer), pipe) != null) {
//            result += buffer;
//        }
//    }
//    catch (...) {
//        _pclose(pipe);
//        throw;
//    }
//    _pclose(pipe);
//    return result;
//}
//
////测试nmap
//int main() {
//    // 执行nmap扫描命令
//    std::string output = exec("nmap -sv 192.168.117.1");
//
//    // 解析nmap扫描结果
//    // 这里你可以编写代码来提取所需的信息，例如开放端口和服务版本号
//    // 这里只是简单地将nmap的输出打印到控制台
//    std::cout << "nmap scan result:" << std::endl;
//    std::cout << output << std::endl;
//
//    system("pause");
//    return 0;
//}
//
////测试ssh链接+基线检测
////int main(int argc, char** argv)
////{
////    //若以root登录，需配置/etc/ssh/sshd_config中的PermitRootLogin yes
////    ssh_session session = initialize_ssh_session("192.168.117.129", "root", "123456");
////    if (session == NULL)
////    {
////        return -1;
////    }
////    vector<event> Event;
////    fun(Event, session);
////    //cout << Event[0].result << endl;
////    ssh_disconnect(session);
////    ssh_free(session);
////
////
////    system("pause");
////    return 0;
////}
//
