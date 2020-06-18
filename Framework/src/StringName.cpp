#include "StringName.h"

namespace nova {

	uint32_t StringName::calculate_hash(const char* str)
	{
		uint32_t hashv = 5381;
		uint32_t c;

		while (*str != '\0') {
			c = *str;
			hashv = ((hashv << 5) + hashv) + c; /* hash * 33 + c */
			++str;
		}

		return hashv;
	}

}
