#pragma once

#include <cstdint>
#include <iostream>
#include <string>

namespace nova {

	/**
	 * @brief A const string with fast comparisons.
	 */
	class StringName {

		const std::string string;
		const uint32_t hash;

		static uint32_t calculate_hash(const char* str);

	public:

		// ============
		// Construction
		// ============

		// Intentionally implicit

		StringName(const char* str) :
			string(str), hash(calculate_hash(str))
		{
		}

		StringName(const std::string& str) :
			string(str), hash(calculate_hash(str.c_str()))
		{
		}

		// =========
		// Operators
		// =========

		// With other StringName

		bool operator==(const StringName& str) const
		{
			if (hash == str.hash) {
				return string == str.string;
			} else {
				return false;
			}
		}

		bool operator!=(const StringName& str) const
		{
			return !(*this == str);
		}

		// With std::string

		bool operator==(const std::string& str) const
		{
			if (hash == calculate_hash(str.c_str())) {
				return string == str;
			} else {
				return false;
			}
		}

		bool operator!=(const std::string& str) const
		{
			return !(*this == str);
		}

		// With cstring

		bool operator==(const char* str) const
		{
			return *this == std::string(str);
		}

		bool operator!=(const char* str) const
		{
			return !(*this == str);
		}

		// =========
		// Interface
		// =========

		[[nodiscard]] const std::string& get_string() const noexcept
		{
			return string;
		}

		[[nodiscard]] uint32_t get_hash() const noexcept
		{
			return hash;
		}

	};

	// =========
	// Operators
	// =========

	// With std::string

	inline bool operator==(const std::string& lhs, const StringName& rhs)
	{
		return rhs == lhs;
	}

	inline bool operator!=(const std::string& lhs, const StringName& rhs)
	{
		return rhs != lhs;
	}

	// With cstring

	inline bool operator==(const char* lhs, const StringName& rhs)
	{
		return rhs == std::string(lhs);
	}

	inline bool operator!=(const char* lhs, const StringName& rhs)
	{
		return rhs != std::string(lhs);
	}


} // namespace nova

namespace std {

	template<>
	struct hash<nova::StringName> {
		size_t operator()(const nova::StringName& sn) const
		{
			return sn.get_hash();
		}
	};
	
} // namespace std

