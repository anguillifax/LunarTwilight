#include "pch.h"
#include "CppUnitTest.h"

#include "StringName.h"

#include <unordered_map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nova;

namespace FrameworkUnitTest {
	TEST_CLASS(StringName_) {
public:
	
	TEST_METHOD(init_from_cstring)
	{
		const char* what = "Foo";
		StringName s(what);
		Assert::AreEqual(std::string(what), s.get_string());
	}

	TEST_METHOD(init_from_string)
	{
		std::string what = "Test";
		StringName s(what);
		Assert::AreEqual(s.get_string(), what);
	}

	TEST_METHOD(same_hash)
	{
		StringName s1("Anguillifax");
		StringName s2("Anguillifax");
		Assert::AreEqual(s1.get_hash(), s2.get_hash());
	}

	TEST_METHOD(with_c_strings)
	{
		StringName s("Foobar");

		Assert::IsTrue(s == "Foobar");
		Assert::IsTrue("Foobar" == s);
		Assert::IsFalse("foobar" == s);
		Assert::IsFalse(s == "foobar");

		Assert::IsFalse(s != "Foobar");
		Assert::IsFalse("Foobar" != s);
		Assert::IsTrue("foobar" != s);
		Assert::IsTrue(s != "foobar");
	}

	TEST_METHOD(with_std_string)
	{
		StringName s(std::string("Aurora"));

		Assert::IsTrue(s == std::string("Aurora"));
		Assert::IsTrue(std::string("Aurora") == s);
		Assert::IsFalse(s == std::string("aurora"));
		Assert::IsFalse(std::string("aurora") == s);

		Assert::IsFalse(s != std::string("Aurora"));
		Assert::IsFalse(std::string("Aurora") != s);
		Assert::IsTrue(s != std::string("aurora"));
		Assert::IsTrue(std::string("aurora") != s);
	}

	TEST_METHOD(with_other_stringname)
	{
		StringName s("Entity");

		Assert::IsTrue(s == StringName("Entity"));
		Assert::IsTrue(StringName("Entity") == s);
		Assert::IsFalse(s == StringName("entity"));
		Assert::IsFalse(StringName("entity") == s);

		Assert::IsFalse(s != StringName("Entity"));
		Assert::IsFalse(StringName("Entity") != s);
		Assert::IsTrue(s != StringName("entity"));
		Assert::IsTrue(StringName("entity") != s);
	}

	TEST_METHOD(with_std_container)
	{
		std::unordered_map<StringName, int> m;
		m.emplace("one", 1);
		m.emplace("two", 2);
		m.emplace("two", 3);

		Assert::AreEqual(m["one"], 1);
		Assert::AreNotEqual(m["two"], 22);
	}

	};
}
