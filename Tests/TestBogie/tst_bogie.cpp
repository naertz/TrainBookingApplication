#include <QtTest>

#include "bogie.h"

class TestBogie : public QObject {
	Q_OBJECT
	public:
		TestBogie(void);
		~TestBogie();
	private slots:
		void test_create_bogie(void);
		void test_create_bogie_with_zero_max_capacity(void);
		void test_create_bogie_with_negative_max_capacity(void);
		void test_add_member_after_empty_capacity(void);
		void test_add_member_after_max_capacity_is_met(void);
		void test_get_empty_bogie_information(void);
		void test_get_partially_full_bogie_information(void);
		void test_get_full_bogie_information(void);
		void test_get_full_bogie_information_after_adding_member_past_max_capacity(void);
};

TestBogie::TestBogie(void) { }

TestBogie::~TestBogie() { }

void TestBogie::test_create_bogie(void) {
	// ARRANGE
	const Bogie bogie { "00", 23 };
	const std::string expected_name = "00";
	const int expected_available_seats = 23;
	const int expected_max_capacity = 23;
	std::string actual_name;
	int actual_available_seats;
	int actual_max_capacity;
	// ACT
	actual_name = bogie.get_name();
	actual_available_seats = bogie.get_available_seats();
	actual_max_capacity = bogie.get_max_capacity();
	// ASSERT
	QCOMPARE(actual_name, expected_name);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_max_capacity, expected_max_capacity);
}

void TestBogie::test_create_bogie_with_zero_max_capacity(void) {
	// ARRANGE
	const Bogie bogie { "00", 0 };
	const std::string expected_name = "00";
	const int expected_available_seats = 1;
	const int expected_max_capacity = 1;
	std::string actual_name;
	int actual_available_seats;
	int actual_max_capacity;
	// ACT
	actual_name = bogie.get_name();
	actual_available_seats = bogie.get_available_seats();
	actual_max_capacity = bogie.get_max_capacity();
	// ASSERT
	QCOMPARE(actual_name, expected_name);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_max_capacity, expected_max_capacity);
}

void TestBogie::test_create_bogie_with_negative_max_capacity(void) {
	// ARRANGE
	const Bogie bogie { "00", -1 };
	const std::string expected_name = "00";
	const int expected_available_seats = 1;
	const int expected_max_capacity = 1;
	std::string actual_name;
	int actual_available_seats;
	int actual_max_capacity;
	// ACT
	actual_name = bogie.get_name();
	actual_available_seats = bogie.get_available_seats();
	actual_max_capacity = bogie.get_max_capacity();
	// ASSERT
	QCOMPARE(actual_name, expected_name);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_max_capacity, expected_max_capacity);
}

void TestBogie::test_add_member_after_empty_capacity(void) {
	// ARRANGE
	Bogie bogie { "01", 3 };
	const int expected = 2;
	int actual;
	// ACT
	bogie.add_member(Member("John", "Doe"));
	actual = bogie.get_available_seats();
	// ASSERT
	QCOMPARE(actual, expected);
}

void TestBogie::test_add_member_after_max_capacity_is_met(void) {
	// ARRANGE
	Bogie bogie { "02", 2 };
	const int expected = 0;
	int actual;
	// ACT
	bogie.add_member(Member("John", "Doe"));
	bogie.add_member(Member("Adam", "Housley"));
	bogie.add_member(Member("Jessica", "Legume"));
	actual = bogie.get_available_seats();
	// ASSERT
	QCOMPARE(actual, expected);
}

void TestBogie::test_get_empty_bogie_information(void) {
	// ARRANGE
	const Bogie bogie { "03", 5 };
	const std::string expected = "Bogie: 03\nEmpty\nEmpty\nEmpty\nEmpty\nEmpty";
	std::string actual;
	// ACT
	actual = bogie.get_bogie_information();
	// ASSERT
	QCOMPARE(actual, expected);
}

void TestBogie::test_get_partially_full_bogie_information(void) {
	// ARRANGE
	Bogie bogie { "04", 4 };
	const std::string expected = "Bogie: 04\nJohn Doe\nAdam Housley\nJessica Legume\nEmpty";
	std::string actual;
	// ACT
	bogie.add_member(Member("John", "Doe"));
	bogie.add_member(Member("Adam", "Housley"));
	bogie.add_member(Member("Jessica", "Legume"));
	actual = bogie.get_bogie_information();
	// ASSERT
	QCOMPARE(actual, expected);
}

void TestBogie::test_get_full_bogie_information(void) {
	// ARRANGE
	Bogie bogie { "05", 3 };
	const std::string expected = "Bogie: 05\nJohn Doe\nAdam Housley\nJessica Legume";
	std::string actual;
	// ACT
	bogie.add_member(Member("John", "Doe"));
	bogie.add_member(Member("Adam", "Housley"));
	bogie.add_member(Member("Jessica", "Legume"));
	actual = bogie.get_bogie_information();
	// ASSERT
	QCOMPARE(actual, expected);
}

void TestBogie::test_get_full_bogie_information_after_adding_member_past_max_capacity(void) {
	// ARRANGE
	Bogie bogie { "06", 2 };
	const std::string expected = "Bogie: 06\nJohn Doe\nAdam Housley";
	std::string actual;
	// ACT
	bogie.add_member(Member("John", "Doe"));
	bogie.add_member(Member("Adam", "Housley"));
	bogie.add_member(Member("Jessica", "Legume"));
	actual = bogie.get_bogie_information();
	// ASSERT
	QCOMPARE(actual, expected);
}

QTEST_APPLESS_MAIN(TestBogie)

#include "tst_bogie.moc"
