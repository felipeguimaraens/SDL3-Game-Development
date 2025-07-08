#pragma once
#include <iostream>
#include <stdexcept>

class SDLcustomException : std::exception
{
	private: char* error_message;
	public:
		SDLcustomException(char* msg) : error_message() {}
			char* what() {
				return error_message;
			}
		}
};

