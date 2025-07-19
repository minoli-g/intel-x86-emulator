#pragma once

#include "../src/memory.hpp"
#include "../src/register.hpp"
#include <fstream>
#include <memory>
#include <unordered_set>

class StateTestUtils
{
public:
	// TODO move these to source
	static std::unordered_set<std::string> registerNames;

	static std::unordered_set<std::string> flagNames;

public:
	static void loadStateFromFile(std::string filePath, RegisterBank& rb, Memory& mem)
	{
		// TODO clear all in inputs before starting
		std::ifstream stateFile;
		stateFile.open(filePath);

		if(!stateFile)
		{
			throw std::runtime_error("File does not exist.");
		}

		std::string line;
		while(std::getline(stateFile, line))
		{
			if(line.empty())
				throw std::runtime_error("File format incorrect");
			size_t delimPos = line.find(' ');
			if(delimPos == std::string::npos)
				throw std::runtime_error("File format incorrect");

			std::string key = line.substr(0, delimPos);
			std::string valueStr = line.substr(delimPos + 1);
			// TODO address possible nullptr below - do a try catch in whole block
			uint32_t value = static_cast<uint32_t>(std::stoul(valueStr, nullptr, 16));

			if(registerNames.find(key) != registerNames.end())
				rb.set(key, value);
			else if(flagNames.find(key) != flagNames.end())
			{
				if (value==1)
					rb.setFlag(key);
			}
			else
			{
				uint32_t keyInt = static_cast<uint32_t>(std::stoul(key, nullptr, 16));
				mem.write(keyInt, value);
			}
		}
		stateFile.close();
	}

	// TODO make the args const after adding consts in RB and Mem
	static bool areRegisterBanksEqual(RegisterBank& r1, RegisterBank& r2)
	{
		for(auto& name : registerNames)
		{
			if(r1.get(name) != r2.get(name))
				return false;
		}
		for(auto& name : flagNames)
		{
			if(r1.getFlag(name) != r2.getFlag(name))
				return false;
		}
		return true;
	}

	static bool areMemoryBanksEqual(Memory& m1, Memory& m2)
	{
		return m1.getMemoryLayout() == m2.getMemoryLayout();
	}
};

std::unordered_set<std::string> StateTestUtils::registerNames = {
	"EAX", "EBX", "ECX", "EDX", "AX",  "BX",  "CX",	 "DX",	  "AH", "BH",
	"CH",  "DH",  "AL",	 "BL",	"CL",  "DL",  "CS",	 "DS",	  "ES", "FS",
	"GS",  "SS",  "ESI", "EDI", "EBP", "EIP", "ESP", "EFLAGS"};

std::unordered_set<std::string> StateTestUtils::flagNames = {"CF",
															 "PF",
															 "AF",
															 "ZF",
															 "SF",
															 "TF",
															 "IF",
															 "DF",
															 "OF",
															 "NT",
															 "RF",
															 "VM",
															 "AC",
															 "VIF",
															 "VIP",
															 "ID"};