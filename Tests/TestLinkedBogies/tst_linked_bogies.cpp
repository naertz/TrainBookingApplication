#include <QtTest>

#include "linked_bogies.h"
#include "linked_bogies_empty_exception.h"
#include "linked_bogies_insufficient_capacity_exception.h"
#include "linked_bogies_invalid_argument_exception.h"
#include "linked_bogies_out_of_range_exception.h"

class TestLinkedBogies : public QObject {
	Q_OBJECT
	public:
		TestLinkedBogies(void);
		~TestLinkedBogies();
	private slots:
		void test_create_empty_linked_bogies(void);
		void test_insert_bogie_in_empty_linked_bogies(void);
		void test_insert_bogie_in_nonempty_linked_bogies(void);
		void test_insert_bogie_at_negative_index(void);
		void test_insert_bogie_at_index_zero_in_empty_linked_bogies(void);
		void test_insert_bogie_at_index_nonzero_in_empty_linked_bogies(void);
		void test_insert_bogie_at_index_zero_in_nonempty_linked_bogies(void);
		void test_insert_bogie_at_index_end_in_nonempty_linked_bogies(void);
		void test_insert_bogie_at_index_past_end_in_nonempty_linked_bogies(void);
		void test_insert_bogie_at_index_middle_in_nonempty_linked_bogies(void);
		void test_replace_nonexisting_bogie_in_empty_linked_bogies_with_new_bogie(void);
		void test_replace_existing_nonempty_nonend_bogie_with_new_bogie(void);
		void test_replace_existing_empty_nonend_bogie_with_new_bogie(void);
		void test_replace_existing_nonempty_end_bogie_with_new_bogie(void);
		void test_replace_existing_empty_end_bogie_with_new_bogie(void);
		void test_replace_nonexisting_bogie_in_nonempty_linked_bogies_with_new_bogie(void);
		void test_remove_nonexisting_bogie_in_empty_linked_bogies(void);
		void test_remove_existing_nonempty_front_bogie(void);
		void test_remove_existing_empty_front_bogie(void);
		void test_remove_existing_nonempty_nonfront_bogie(void);
		void test_remove_existing_empty_nonfront_bogie(void);
		void test_remove_nonexisting_bogie_in_nonempty_linked_bogies(void);
		void test_remove_bogie_at_negative_index(void);
		void test_remove_nonexisting_bogie_at_nonnegative_index_in_empty_linked_bogies(void);
		void test_remove_existing_nonempty_bogie_at_index_zero(void);
		void test_remove_existing_empty_bogie_at_index_zero(void);
		void test_remove_existing_nonempty_bogie_at_index_end(void);
		void test_remove_existing_empty_bogie_at_index_end(void);
		void test_remove_nonexisting_bogie_at_index_past_end(void);
		void test_remove_existing_nonempty_bogie_at_index_middle(void);
		void test_remove_existing_empty_bogie_at_index_middle(void);
		void test_get_bogie_at_negative_index(void);
		void test_get_nonexisting_bogie_at_nonnegative_index_in_empty_linked_bogies(void);
		void test_get_bogie_at_index_zero(void);
		void test_get_bogie_at_index_end(void);
		void test_get_nonexisting_bogie_at_index_past_end(void);
		void test_get_bogie_at_index_middle(void);
		void test_get_empty_size(void);
		void test_get_nonempty_size(void);
		void test_is_empty(void);
		void test_is_not_empty(void);
		void test_get_available_seats_in_empty_linked_bogies(void);
		void test_get_available_seats_in_nonempty_linked_bogies(void);
		void test_get_available_seats_in_filled_linked_bogies(void);
		void test_dequeue_empty_customer_queue(void);
		void test_dequeue_customers_in_empty_linked_bogies(void);
		void test_dequeue_customers_when_seats_are_unavailable(void);
		void test_dequeue_customers_when_first_party_is_greater_than_seats_available(void);
		void test_dequeue_customers_when_first_party_is_equal_to_seats_available(void);
		void test_dequeue_customers_when_first_party_is_less_than_seats_available(void);
		void test_send_empty_train(void);
		void test_send_unfilled_nonempty_train(void);
		void test_send_partially_filled_nonempty_train(void);
		void test_send_filled_nonempty_train(void);
		void test_get_bogies_list_in_empty_linked_bogies(void);
		void test_get_bogies_list_in_unfilled_nonempty_linked_bogies(void);
		void test_get_bogies_list_in_partially_filled_nonempty_linked_bogies(void);
		void test_get_bogies_list_in_filled_nonempty_linked_bogies(void);
};

TestLinkedBogies::TestLinkedBogies(void) {}

TestLinkedBogies::~TestLinkedBogies() {}

void TestLinkedBogies::test_create_empty_linked_bogies(void) {
	// ARRANGE
	const LinkedBogies linked_bogies;
	const int expected_size = 0;
	const bool expected_is_empty_result = true;
	const int expected_available_seats = 0;
	const std::string expected_bogies_list = "There are no bogies in the train.";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_insert_bogie_in_empty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogie { "00", 5 };
	const int expected_size = 1;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 5;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\nEmpty\nEmpty\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.insert(new_bogie);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_insert_bogie_in_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogies[2] { { "00", 5 }, { "01", 4 } };
	linked_bogies.insert(new_bogies[0]);
	const int expected_size = 2;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 9;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\nEmpty\nEmpty\nEmpty\nEmpty\n\nBogie: 01\nEmpty\nEmpty\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.insert(new_bogies[1]);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_insert_bogie_at_negative_index(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogie { "00", 5 };
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.insert_at(new_bogie, -1), LinkedBogiesOutOfRangeException);
}

void TestLinkedBogies::test_insert_bogie_at_index_zero_in_empty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogie { "00", 3 };
	const int expected_size = 1;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 3;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.insert_at(new_bogie, 0);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_insert_bogie_at_index_nonzero_in_empty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogie { "00", 7 };
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.insert_at(new_bogie, 1), LinkedBogiesOutOfRangeException);
}

void TestLinkedBogies::test_insert_bogie_at_index_zero_in_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogies[2] { { "00", 7 }, { "01", 3 } };
	linked_bogies.insert(new_bogies[0]);
	const int expected_size = 2;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 10;
	const std::string expected_bogies_list = "Bogie: 01\nEmpty\nEmpty\nEmpty\n\nBogie: 00\nEmpty\nEmpty\nEmpty\nEmpty\nEmpty\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.insert_at(new_bogies[1], 0);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_insert_bogie_at_index_end_in_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogies[3] { { "00", 1 }, { "01", 3 }, { "02", 2 } };
	linked_bogies.insert(new_bogies[0]);
	linked_bogies.insert(new_bogies[1]);
	const int expected_size = 3;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 6;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\n\nBogie: 01\nEmpty\nEmpty\nEmpty\n\nBogie: 02\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.insert_at(new_bogies[2], 2);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_insert_bogie_at_index_past_end_in_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogies[3] { { "00", 6 }, { "01", 2 }, { "02", 3 } };
	linked_bogies.insert(new_bogies[0]);
	linked_bogies.insert(new_bogies[1]);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.insert_at(new_bogies[2], 3), LinkedBogiesOutOfRangeException);
}

void TestLinkedBogies::test_insert_bogie_at_index_middle_in_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie new_bogies[3] { { "00", 2 }, { "01", 2 }, { "02", 3 } };
	linked_bogies.insert(new_bogies[0]);
	linked_bogies.insert(new_bogies[1]);
	const int expected_size = 3;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 7;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\nEmpty\n\nBogie: 02\nEmpty\nEmpty\nEmpty\n\nBogie: 01\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.insert_at(new_bogies[2], 1);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_replace_nonexisting_bogie_in_empty_linked_bogies_with_new_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string old_bogie_name = "00";
	const Bogie new_bogie { "01", 7 };
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.replace(old_bogie_name, new_bogie), LinkedBogiesEmptyException);
}

void TestLinkedBogies::test_replace_existing_nonempty_nonend_bogie_with_new_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string old_bogie_name = "01";
	const Bogie old_bogies[3] { Bogie("00", 1), Bogie(old_bogie_name, 5), Bogie("02", 2) };
	linked_bogies.insert(old_bogies[0]);
	linked_bogies.insert(old_bogies[1]);
	linked_bogies.insert(old_bogies[2]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	const Bogie new_bogie { old_bogie_name, 3 };
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.replace(old_bogie_name, new_bogie), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_replace_existing_empty_nonend_bogie_with_new_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string old_bogie_name = "01";
	const Bogie old_bogies[3] { Bogie("00", 1), Bogie(old_bogie_name, 5), Bogie("02", 2) };
	linked_bogies.insert(old_bogies[0]);
	linked_bogies.insert(old_bogies[1]);
	linked_bogies.insert(old_bogies[2]);
	const Bogie new_bogie { old_bogie_name, 3 };
	const int expected_size = 3;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 6;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\n\nBogie: 01\nEmpty\nEmpty\nEmpty\n\nBogie: 02\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.replace(old_bogie_name, new_bogie);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_replace_existing_nonempty_end_bogie_with_new_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string old_bogie_name = "01";
	const Bogie old_bogies[2] { Bogie("00", 1), Bogie(old_bogie_name, 5) };
	linked_bogies.insert(old_bogies[0]);
	linked_bogies.insert(old_bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	const Bogie new_bogie { old_bogie_name, 3 };
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.replace(old_bogie_name, new_bogie), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_replace_existing_empty_end_bogie_with_new_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string old_bogie_name = "01";
	const Bogie old_bogies[2] { Bogie("00", 1), Bogie(old_bogie_name, 5) };
	linked_bogies.insert(old_bogies[0]);
	linked_bogies.insert(old_bogies[1]);
	const Bogie new_bogie { old_bogie_name, 3 };
	const int expected_size = 2;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 4;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\n\nBogie: 01\nEmpty\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.replace(old_bogie_name, new_bogie);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_replace_nonexisting_bogie_in_nonempty_linked_bogies_with_new_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie old_bogies[2] { Bogie("00", 1), Bogie("01", 5) };
	linked_bogies.insert(old_bogies[0]);
	linked_bogies.insert(old_bogies[1]);
	const Bogie new_bogie { "03", 3 };
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.replace("02", new_bogie), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_remove_nonexisting_bogie_in_empty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string bogie_name = "00";;
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove(bogie_name), LinkedBogiesEmptyException);
}

void TestLinkedBogies::test_remove_existing_nonempty_front_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string bogie_name = "00";
	const Bogie bogie { bogie_name, 3 };
	linked_bogies.insert(bogie);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove(bogie_name), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_remove_existing_empty_front_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string bogie_name = "00";
	const Bogie bogies[2] { Bogie(bogie_name, 5), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	const int expected_size = 1;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 2;
	const std::string expected_bogies_list = "Bogie: 01\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.remove(bogie_name);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_remove_existing_nonempty_nonfront_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string bogie_name = "01";
	const Bogie bogies[2] { Bogie("00", 1), Bogie(bogie_name, 5) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove(bogie_name), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_remove_existing_empty_nonfront_bogie(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string bogie_name = "01";
	const Bogie bogies[2] { Bogie("00", 5), Bogie(bogie_name, 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	const int expected_size = 1;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 5;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\nEmpty\nEmpty\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.remove(bogie_name);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_remove_nonexisting_bogie_in_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 1), Bogie("01", 5) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove("02"), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_remove_bogie_at_negative_index(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 5 };
	linked_bogies.insert(bogie);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove_at(-1), LinkedBogiesOutOfRangeException);
}

void TestLinkedBogies::test_remove_nonexisting_bogie_at_nonnegative_index_in_empty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove_at(0), LinkedBogiesEmptyException);
}

void TestLinkedBogies::test_remove_existing_nonempty_bogie_at_index_zero(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 3 };
	linked_bogies.insert(bogie);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove_at(0), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_remove_existing_empty_bogie_at_index_zero(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 5), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	const int expected_size = 1;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 2;
	const std::string expected_bogies_list = "Bogie: 01\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.remove_at(0);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_remove_existing_nonempty_bogie_at_index_end(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[3] { Bogie("00", 1), Bogie("01", 1), Bogie("02", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	linked_bogies.insert(bogies[2]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10), PartyMember("Jenna", "Appleroot", 4), PartyMember("Joel", "Appleskull", 95) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove_at(2), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_remove_existing_empty_bogie_at_index_end(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[3] { Bogie("00", 1), Bogie("01", 2), Bogie("02", 3) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	linked_bogies.insert(bogies[2]);
	const int expected_size = 2;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 3;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\n\nBogie: 01\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.remove_at(2);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_remove_nonexisting_bogie_at_index_past_end(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[3] { Bogie("00", 1), Bogie("01", 1), Bogie("02", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	linked_bogies.insert(bogies[2]);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove_at(3), LinkedBogiesOutOfRangeException);
}

void TestLinkedBogies::test_remove_existing_nonempty_bogie_at_index_middle(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[3] { Bogie("00", 1), Bogie("01", 1), Bogie("02", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	linked_bogies.insert(bogies[2]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10), PartyMember("Jenna", "Appleroot", 4), PartyMember("Joel", "Appleskull", 95) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.remove_at(1), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_remove_existing_empty_bogie_at_index_middle(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[3] { Bogie("00", 1), Bogie("01", 2), Bogie("02", 3) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	linked_bogies.insert(bogies[2]);
	const int expected_size = 2;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 4;
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\n\nBogie: 02\nEmpty\nEmpty\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.remove_at(1);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_get_bogie_at_negative_index(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.get(-1), LinkedBogiesOutOfRangeException);
}

void TestLinkedBogies::test_get_nonexisting_bogie_at_nonnegative_index_in_empty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.get(0), LinkedBogiesEmptyException);
}

void TestLinkedBogies::test_get_bogie_at_index_zero(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 5 };
	linked_bogies.insert(bogie);
	const std::string expected_bogie_name = "00";
	const int expected_bogie_available_seats = 5;
	const int expected_bogie_max_capacity = 5;
	std::string actual_bogie_name;
	int actual_bogie_available_seats;
	int actual_bogie_max_capacity;
	// ACT
	actual_bogie_name = linked_bogies.get(0).get_name();
	actual_bogie_available_seats = linked_bogies.get(0).get_available_seats();
	actual_bogie_max_capacity = linked_bogies.get(0).get_max_capacity();
	// ASSERT
	QCOMPARE(actual_bogie_name, expected_bogie_name);
	QCOMPARE(actual_bogie_available_seats, expected_bogie_available_seats);
	QCOMPARE(actual_bogie_max_capacity, expected_bogie_max_capacity);
}

void TestLinkedBogies::test_get_bogie_at_index_end(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 5), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	const std::string expected_bogie_name = "01";
	const int expected_bogie_available_seats = 2;
	const int expected_bogie_max_capacity = 2;
	std::string actual_bogie_name;
	int actual_bogie_available_seats;
	int actual_bogie_max_capacity;
	// ACT
	actual_bogie_name = linked_bogies.get(1).get_name();
	actual_bogie_available_seats = linked_bogies.get(1).get_available_seats();
	actual_bogie_max_capacity = linked_bogies.get(1).get_max_capacity();
	// ASSERT
	QCOMPARE(actual_bogie_name, expected_bogie_name);
	QCOMPARE(actual_bogie_available_seats, expected_bogie_available_seats);
	QCOMPARE(actual_bogie_max_capacity, expected_bogie_max_capacity);
}

void TestLinkedBogies::test_get_nonexisting_bogie_at_index_past_end(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[3] { Bogie("b0", 5), Bogie("b1", 8), Bogie("b2", 3) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	linked_bogies.insert(bogies[2]);
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.get(3), LinkedBogiesOutOfRangeException);
}

void TestLinkedBogies::test_get_bogie_at_index_middle(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[3] { Bogie("A0", 5), Bogie("A1", 8), Bogie("A2", 3) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	linked_bogies.insert(bogies[2]);
	const std::string expected_bogie_name = "A1";
	const int expected_bogie_available_seats = 8;
	const int expected_bogie_max_capacity = 8;
	std::string actual_bogie_name;
	int actual_bogie_available_seats;
	int actual_bogie_max_capacity;
	// ACT
	actual_bogie_name = linked_bogies.get(1).get_name();
	actual_bogie_available_seats = linked_bogies.get(1).get_available_seats();
	actual_bogie_max_capacity = linked_bogies.get(1).get_max_capacity();
	// ASSERT
	QCOMPARE(actual_bogie_name, expected_bogie_name);
	QCOMPARE(actual_bogie_available_seats, expected_bogie_available_seats);
	QCOMPARE(actual_bogie_max_capacity, expected_bogie_max_capacity);
}

void TestLinkedBogies::test_get_empty_size(void) {
	// ARRANGE
	const LinkedBogies linked_bogies;
	const int expected_size = 0;
	int actual_size;
	// ACT
	actual_size = linked_bogies.get_size();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
}

void TestLinkedBogies::test_get_nonempty_size(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 5 };
	linked_bogies.insert(bogie);
	const int expected_size = 1;
	int actual_size;
	// ACT
	actual_size = linked_bogies.get_size();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
}

void TestLinkedBogies::test_is_empty(void) {
	// ARRANGE
	const LinkedBogies linked_bogies;
	const bool expected_is_empty_result = true;
	int actual_is_empty_result;
	// ACT
	actual_is_empty_result = linked_bogies.is_empty();
	// ASSERT
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
}

void TestLinkedBogies::test_is_not_empty(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 5 };
	linked_bogies.insert(bogie);
	const bool expected_is_empty_result = false;
	int actual_is_empty_result;
	// ACT
	actual_is_empty_result = linked_bogies.is_empty();
	// ASSERT
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
}

void TestLinkedBogies::test_get_available_seats_in_empty_linked_bogies(void) {
	// ARRANGE
	const LinkedBogies linked_bogies;
	const int expected_available_seats = 0;
	int actual_available_seats;
	// ACT
	actual_available_seats = linked_bogies.get_available_seats();
	// ASSERT
	QCOMPARE(actual_available_seats, expected_available_seats);
}

void TestLinkedBogies::test_get_available_seats_in_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 5 };
	linked_bogies.insert(bogie);
	const int expected_available_seats = 5;
	int actual_available_seats;
	// ACT
	actual_available_seats = linked_bogies.get_available_seats();
	// ASSERT
	QCOMPARE(actual_available_seats, expected_available_seats);
}

void TestLinkedBogies::test_get_available_seats_in_filled_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 2), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10), PartyMember("Jenna", "Appleroot", 4), PartyMember("Joel", "Appleskull", 95) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	const int expected_available_seats = 0;
	int actual_available_seats;
	// ACT
	actual_available_seats = linked_bogies.get_available_seats();
	// ASSERT
	QCOMPARE(actual_available_seats, expected_available_seats);
}

void TestLinkedBogies::test_dequeue_empty_customer_queue(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const std::string bogie_name = "00";
	const Bogie bogie { bogie_name, 3 };
	linked_bogies.insert(bogie);
	std::priority_queue<Customer> customer_queue;
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.dequeue_customers(customer_queue), LinkedBogiesInvalidArgumentException);
}

void TestLinkedBogies::test_dequeue_customers_in_empty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.dequeue_customers(customer_queue), LinkedBogiesEmptyException);
}

void TestLinkedBogies::test_dequeue_customers_when_seats_are_unavailable(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 4 };
	linked_bogies.insert(bogie);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10), PartyMember("Jenna", "Appleroot", 4), PartyMember("Joel", "Appleskull", 95) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	customer_queue.push(Customer("Maven", "Rocksmith", {}, "Cedar Falls, Iowa", false));
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.dequeue_customers(customer_queue), LinkedBogiesInsufficientCapacityException);
}

void TestLinkedBogies::test_dequeue_customers_when_first_party_is_greater_than_seats_available(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 5 };
	linked_bogies.insert(bogie);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10), PartyMember("Jenna", "Appleroot", 4), PartyMember("Joel", "Appleskull", 95) }, "Cedar Rapids, Iowa", false));
	linked_bogies.dequeue_customers(customer_queue);
	customer_queue.push(Customer("Maven", "Rocksmith", { PartyMember("Billy", "Rockwell", 5) }, "Cedar Falls, Iowa", false));
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.dequeue_customers(customer_queue), LinkedBogiesInsufficientCapacityException);
}

void TestLinkedBogies::test_dequeue_customers_when_first_party_is_equal_to_seats_available(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 1), Bogie("01", 1) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	customer_queue.push(Customer("Maven", "Rocksmith", { PartyMember("Billy", "Rockwell", 5) }, "Cedar Falls, Iowa", true));
	const int expected_size = 2;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 0;
	const std::string expected_bogies_list = "Bogie: 00\nMaven Rocksmith\n\nBogie: 01\nBilly Rockwell";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.dequeue_customers(customer_queue);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_dequeue_customers_when_first_party_is_less_than_seats_available(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 1), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	customer_queue.push(Customer("Maven", "Rocksmith", { PartyMember("Billy", "Rockwell", 5) }, "Cedar Falls, Iowa", true));
	const int expected_size = 2;
	const bool expected_is_empty_result = false;
	const int expected_available_seats = 1;
	const std::string expected_bogies_list = "Bogie: 00\nMaven Rocksmith\n\nBogie: 01\nBilly Rockwell\nEmpty";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.dequeue_customers(customer_queue);
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_send_empty_train(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	// ACT & ASSERT
	QVERIFY_EXCEPTION_THROWN(linked_bogies.send_train(), LinkedBogiesEmptyException);
}

void TestLinkedBogies::test_send_unfilled_nonempty_train(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogie { "00", 4 };
	linked_bogies.insert(bogie);
	const int expected_size = 0;
	const bool expected_is_empty_result = true;
	const int expected_available_seats = 0;
	const std::string expected_bogies_list = "There are no bogies in the train.";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.send_train();
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_send_partially_filled_nonempty_train(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 4), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	customer_queue.push(Customer("Maven", "Rocksmith", { PartyMember("Billy", "Rockwell", 5) }, "Cedar Falls, Iowa", true));
	linked_bogies.dequeue_customers(customer_queue);
	const int expected_size = 0;
	const bool expected_is_empty_result = true;
	const int expected_available_seats = 0;
	const std::string expected_bogies_list = "There are no bogies in the train.";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.send_train();
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_send_filled_nonempty_train(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 4), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Seth", "Applesmith", { PartyMember("Johnny", "Appleseed", 10) }, "Cedar Rapids, Iowa", false));
	customer_queue.push(Customer("Maven", "Rocksmith", { PartyMember("Billy", "Rockwell", 5), PartyMember("Sam", "Rockwise", 25), PartyMember("Pippin", "Rocktook", 22) }, "Cedar Falls, Iowa", true));
	linked_bogies.dequeue_customers(customer_queue);
	const int expected_size = 0;
	const bool expected_is_empty_result = true;
	const int expected_available_seats = 0;
	const std::string expected_bogies_list = "There are no bogies in the train.";
	int actual_size;
	bool actual_is_empty_result;
	int actual_available_seats;
	std::string actual_bogies_list;
	// ACT
	linked_bogies.send_train();
	actual_size = linked_bogies.get_size();
	actual_is_empty_result = linked_bogies.is_empty();
	actual_available_seats = linked_bogies.get_available_seats();
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_size, expected_size);
	QCOMPARE(actual_is_empty_result, expected_is_empty_result);
	QCOMPARE(actual_available_seats, expected_available_seats);
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_get_bogies_list_in_empty_linked_bogies(void) {
	// ARRANGE
	const LinkedBogies linked_bogies;
	const std::string expected_bogies_list = "There are no bogies in the train.";
	std::string actual_bogies_list;
	// ACT
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_get_bogies_list_in_unfilled_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 4), Bogie("01", 1) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	const std::string expected_bogies_list = "Bogie: 00\nEmpty\nEmpty\nEmpty\nEmpty\n\nBogie: 01\nEmpty";
	std::string actual_bogies_list;
	// ACT
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_get_bogies_list_in_partially_filled_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 4), Bogie("01", 1) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Maven", "Rocksmith", { PartyMember("Billy", "Rockwell", 5), PartyMember("Sam", "Rockwise", 25) }, "Cedar Falls, Iowa", true));
	linked_bogies.dequeue_customers(customer_queue);
	const std::string expected_bogies_list = "Bogie: 00\nMaven Rocksmith\nBilly Rockwell\nSam Rockwise\nEmpty\n\nBogie: 01\nEmpty";
	std::string actual_bogies_list;
	// ACT
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

void TestLinkedBogies::test_get_bogies_list_in_filled_nonempty_linked_bogies(void) {
	// ARRANGE
	LinkedBogies linked_bogies;
	const Bogie bogies[2] { Bogie("00", 2), Bogie("01", 2) };
	linked_bogies.insert(bogies[0]);
	linked_bogies.insert(bogies[1]);
	std::priority_queue<Customer> customer_queue;
	customer_queue.push(Customer("Maven", "Rocksmith", { PartyMember("Billy", "Rockwell", 5), PartyMember("Sam", "Rockwise", 25), PartyMember("Pippin", "Rocktook", 22) }, "Cedar Falls, Iowa", true));
	linked_bogies.dequeue_customers(customer_queue);
	const std::string expected_bogies_list = "Bogie: 00\nMaven Rocksmith\nBilly Rockwell\n\nBogie: 01\nPippin Rocktook\nSam Rockwise";
	std::string actual_bogies_list;
	// ACT
	actual_bogies_list = linked_bogies.get_bogies_list();
	// ASSERT
	QCOMPARE(actual_bogies_list, expected_bogies_list);
}

QTEST_APPLESS_MAIN(TestLinkedBogies)

#include "tst_linked_bogies.moc"
