#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

using SIZE_32 = uint32_t;
using SIZE_16 = uint16_t;
using SIZE_8 = uint8_t;

template <typename SIZE>
class Register
{
	std::string m_name;
	SIZE* m_data;

	void clear();

	template <typename T>
	void set(T value) = delete;

	void set(SIZE value)
	{
		*m_data = value;
	}
};

class Flag
{
	std::string name;
	uint32_t* m_flagRegisterData;
	uint8_t index;

	void set()
	{
		*m_flagRegisterData |= (1 << index);
	}
	void clear()
	{
		*m_flagRegisterData &= (0xFFFF - (1 << index));
	}
};

class RegisterBank
{
private:
	// Add more if larger sizes need to be supported.
	// Also think about maintaining a reverse mapping of name to map for fast lookup.
	std::unordered_map<std::string, Register<SIZE_32>*> m_32BitRegs;
	std::unordered_map<std::string, Register<SIZE_16>*> m_16BitRegs;
	std::unordered_map<std::string, Register<SIZE_8>*> m_8BitRegs;

	std::unordered_map<std::string, Flag*> m_flags;

public:
	void loadLayoutFromFile(std::string filePath);
};