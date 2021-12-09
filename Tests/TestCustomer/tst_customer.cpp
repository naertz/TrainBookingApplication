#include <QtTest>

#include <queue>

#include "customer.h"

class TestCustomer : public QObject {
	Q_OBJECT
	public:
		TestCustomer(void);
		~TestCustomer();
	private slots:
		void test_create_customer(void);
		void test_insertion_sort(void);
		void test_is_fast_lane_comparison(void);
		void test_priority_queue(void);
};

TestCustomer::TestCustomer(void) { }

TestCustomer::~TestCustomer() { }

void TestCustomer::test_create_customer(void) {
	// ARRANGE
	const Customer customer { "Samuel", "Hayden", { PartyMember("John", "Doe", 25), PartyMember("Jessica", "Maven", 35), PartyMember("Joel", "Yoel", 4) }, "Ankeny, Iowa", true };
	const std::string expected_customer_first_name = "Samuel";
	const std::string expected_customer_last_name = "Hayden";
	const std::string expected_party_members_first_names[3] = { "Joel", "John", "Jessica" };
	const std::string expected_party_members_last_names[3] = { "Yoel", "Doe", "Maven" };
	const int expected_party_members_ages[3] = { 4, 25, 35 };
	const int expected_party_size = 4;
	const std::string expected_destination = "Ankeny, Iowa";
	std::string actual_customer_first_name;
	std::string actual_customer_last_name;
	std::string actual_party_members_first_names[3];
	std::string actual_party_members_last_names[3];
	int actual_party_members_ages[3];
	int actual_party_size;
	std::string actual_destination;
	// ACT
	actual_customer_first_name = customer.get_first_name();
	actual_customer_last_name = customer.get_last_name();
	actual_party_members_first_names[0] = customer.get_party()[0].get_first_name();
	actual_party_members_first_names[1] = customer.get_party()[1].get_first_name();
	actual_party_members_first_names[2] = customer.get_party()[2].get_first_name();
	actual_party_members_last_names[0] = customer.get_party()[0].get_last_name();
	actual_party_members_last_names[1] = customer.get_party()[1].get_last_name();
	actual_party_members_last_names[2] = customer.get_party()[2].get_last_name();
	actual_party_members_ages[0] = customer.get_party()[0].get_age();
	actual_party_members_ages[1] = customer.get_party()[1].get_age();
	actual_party_members_ages[2] = customer.get_party()[2].get_age();
	actual_party_size = customer.get_party_size();
	actual_destination = customer.get_destination();
	// ASSERT
	QCOMPARE(actual_customer_first_name, expected_customer_first_name);
	QCOMPARE(actual_customer_last_name, expected_customer_last_name);
	QCOMPARE(actual_party_members_first_names[0], expected_party_members_first_names[0]);
	QCOMPARE(actual_party_members_first_names[1], expected_party_members_first_names[1]);
	QCOMPARE(actual_party_members_first_names[2], expected_party_members_first_names[2]);
	QCOMPARE(actual_party_members_last_names[0], expected_party_members_last_names[0]);
	QCOMPARE(actual_party_members_last_names[1], expected_party_members_last_names[1]);
	QCOMPARE(actual_party_members_last_names[2], expected_party_members_last_names[2]);
	QCOMPARE(actual_party_members_ages[0], expected_party_members_ages[0]);
	QCOMPARE(actual_party_members_ages[1], expected_party_members_ages[1]);
	QCOMPARE(actual_party_members_ages[2], expected_party_members_ages[2]);
	QCOMPARE(actual_party_size, expected_party_size);
	QCOMPARE(actual_destination, expected_destination);
}

void TestCustomer::test_insertion_sort() {
	// ARRANGE
	const Customer customer { "Samuel", "Hayden", { PartyMember("John", "Doe", 25), PartyMember("Jessica", "Maven", 35), PartyMember("Joel", "Yoel", 4), PartyMember("Jen", "Benson", 25), PartyMember("Jack", "Black", 50), PartyMember("Justin", "Billward", 33) }, "Ankeny, Iowa", true };
	const bool expected_is_sort_successful = true;
	bool actual_is_sort_successful;
	// ACT
	actual_is_sort_successful = customer.get_party()[0].get_age() <= customer.get_party()[1].get_age() &&
	                            customer.get_party()[1].get_age() <= customer.get_party()[2].get_age() &&
	                            customer.get_party()[2].get_age() <= customer.get_party()[3].get_age() &&
	                            customer.get_party()[3].get_age() <= customer.get_party()[4].get_age() &&
	                            customer.get_party()[4].get_age() <= customer.get_party()[5].get_age();
	// ASSERT
	QCOMPARE(actual_is_sort_successful, expected_is_sort_successful);
}

void TestCustomer::test_is_fast_lane_comparison() {
	// ARRANGE
	const Customer fast_lane_customers[2] { Customer("Samuel", "Hayden", { PartyMember("John", "Doe", 25) }, "Ankeny, Iowa", true), Customer("Samuel", "Jackson", { }, "Des Moines, Iowa", true) };
	const Customer regular_customers[2] { Customer("John", "Wick", { }, "Newton, Iowa", false), Customer("Keanu", "Reeves", { PartyMember("Adam", "Johnson", 40), PartyMember("Ariel", "Anderson", 5) }, "Boone, Iowa", false) };
	const bool expected_is_fast_lane_less_than_fast_lane = false;
	const bool expected_is_fast_lane_less_than_regular = false;
	const bool expected_is_regular_less_than_fast_lane = true;
	const bool expected_is_regular_less_than_regular = false;
	bool actual_is_fast_lane_less_than_fast_lane;
	bool actual_is_fast_lane_less_than_regular;
	bool actual_is_regular_less_than_fast_lane;
	bool actual_is_regular_less_than_regular;
	// ACT
	actual_is_fast_lane_less_than_fast_lane = fast_lane_customers[0] < fast_lane_customers[1];
	actual_is_fast_lane_less_than_regular = fast_lane_customers[0] < regular_customers[0];
	actual_is_regular_less_than_fast_lane = regular_customers[1] < fast_lane_customers[1];
	actual_is_regular_less_than_regular = regular_customers[0] < regular_customers[1];
	// ASSERT
	QCOMPARE(actual_is_fast_lane_less_than_fast_lane, expected_is_fast_lane_less_than_fast_lane);
	QCOMPARE(actual_is_fast_lane_less_than_regular, expected_is_fast_lane_less_than_regular);
	QCOMPARE(actual_is_regular_less_than_fast_lane, expected_is_regular_less_than_fast_lane);
	QCOMPARE(actual_is_regular_less_than_regular, expected_is_regular_less_than_regular);
}

void TestCustomer::test_priority_queue() {
	// ARRANGE
	const Customer fast_lane_customers[2] { Customer("Samuel", "Hayden", { PartyMember("John", "Doe", 25) }, "Ankeny, Iowa", true), Customer("Andrew", "Jackson", { }, "Des Moines, Iowa", true) };
	const Customer regular_customers[2] { Customer("John", "Wick", { }, "Newton, Iowa", false), Customer("Keanu", "Reeves", { PartyMember("Adam", "Johnson", 40), PartyMember("Ariel", "Anderson", 5) }, "Boone, Iowa", false) };
	std::priority_queue<Customer> customer_queue;
	const std::string expected_customers_first_names[4] = { "Samuel", "Andrew", "John", "Keanu" };
	const std::string expected_customers_last_names[4] = { "Hayden", "Jackson", "Wick", "Reeves" };
	std::string actual_customers_first_names[4];
	std::string actual_customers_last_names[4];
	// ACT
	customer_queue.push(regular_customers[0]);
	customer_queue.push(fast_lane_customers[0]);
	customer_queue.push(regular_customers[1]);
	customer_queue.push(fast_lane_customers[1]);
	actual_customers_first_names[0] = customer_queue.top().get_first_name();
	actual_customers_last_names[0] = customer_queue.top().get_last_name();
	customer_queue.pop();
	actual_customers_first_names[1] = customer_queue.top().get_first_name();
	actual_customers_last_names[1] = customer_queue.top().get_last_name();
	customer_queue.pop();
	actual_customers_first_names[2] = customer_queue.top().get_first_name();
	actual_customers_last_names[2] = customer_queue.top().get_last_name();
	customer_queue.pop();
	actual_customers_first_names[3] = customer_queue.top().get_first_name();
	actual_customers_last_names[3] = customer_queue.top().get_last_name();
	customer_queue.pop();
	// ASSERT
	QCOMPARE(actual_customers_first_names[0], expected_customers_first_names[0]);
	QCOMPARE(actual_customers_first_names[1], expected_customers_first_names[1]);
	QCOMPARE(actual_customers_first_names[2], expected_customers_first_names[2]);
	QCOMPARE(actual_customers_first_names[3], expected_customers_first_names[3]);
	QCOMPARE(actual_customers_last_names[0], expected_customers_last_names[0]);
	QCOMPARE(actual_customers_last_names[1], expected_customers_last_names[1]);
	QCOMPARE(actual_customers_last_names[2], expected_customers_last_names[2]);
	QCOMPARE(actual_customers_last_names[3], expected_customers_last_names[3]);
}

QTEST_APPLESS_MAIN(TestCustomer)

#include "tst_customer.moc"
