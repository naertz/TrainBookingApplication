#include <QtTest>

#include "node.h"

class TestNode : public QObject {
	Q_OBJECT
	public:
		TestNode(void);
		~TestNode();
	private slots:
		void test_create_node(void);
		void test_set_bogie(void);
		void test_set_next_node(void);
};

TestNode::TestNode(void) { }

TestNode::~TestNode() { }

void TestNode::test_create_node(void) {
	// ARRANGE
	Node node { Bogie("00", 23) };
	const std::string expected_bogie_name = "00";
	const int expected_bogie_available_seats = 23;
	const int expected_bogie_max_capacity = 23;
	const Node *expected_next_node = nullptr;
	std::string actual_bogie_name;
	int actual_bogie_available_seats;
	int actual_bogie_max_capacity;
	Node *actual_next_node;
	// ACT
	actual_bogie_name = node.get_bogie().get_name();
	actual_bogie_available_seats = node.get_bogie().get_available_seats();
	actual_bogie_max_capacity = node.get_bogie().get_max_capacity();
	actual_next_node = node.get_next_node();
	// ASSERT
	QCOMPARE(actual_bogie_name, expected_bogie_name);
	QCOMPARE(actual_bogie_available_seats, expected_bogie_available_seats);
	QCOMPARE(actual_bogie_max_capacity, expected_bogie_max_capacity);
	QCOMPARE(actual_next_node, expected_next_node);
}

void TestNode::test_set_bogie(void) {
	// ARRANGE
	Node node { Bogie("00", 23) };
	const std::string expected_bogie_name = "01";
	const int expected_bogie_available_seats = 5;
	const int expected_bogie_max_capacity = 5;
	const Node *expected_next_node = nullptr;
	std::string actual_bogie_name;
	int actual_bogie_available_seats;
	int actual_bogie_max_capacity;
	Node *actual_next_node;
	// ACT
	node.set_bogie(Bogie("01", 5));
	actual_bogie_name = node.get_bogie().get_name();
	actual_bogie_available_seats = node.get_bogie().get_available_seats();
	actual_bogie_max_capacity = node.get_bogie().get_max_capacity();
	actual_next_node = node.get_next_node();
	// ASSERT
	QCOMPARE(actual_bogie_name, expected_bogie_name);
	QCOMPARE(actual_bogie_available_seats, expected_bogie_available_seats);
	QCOMPARE(actual_bogie_max_capacity, expected_bogie_max_capacity);
	QCOMPARE(actual_next_node, expected_next_node);
}

void TestNode::test_set_next_node(void) {
	// ARRANGE
	Node node { Bogie("00", 23) };
	Node *next_node = new Node(Bogie("01", 5));
	const std::string expected_bogie_name = "00";
	const int expected_bogie_available_seats = 23;
	const int expected_bogie_max_capacity = 23;
	const std::string expected_next_node_bogie_name = "01";
	const int expected_next_node_bogie_available_seats = 5;
	const int expected_next_node_bogie_max_capacity = 5;
	const Node *expected_next_node_next_node = nullptr;
	std::string actual_bogie_name;
	int actual_bogie_available_seats;
	int actual_bogie_max_capacity;
	std::string actual_next_node_bogie_name;
	int actual_next_node_bogie_available_seats;
	int actual_next_node_bogie_max_capacity;
	Node *actual_next_node_next_node;
	// ACT
	node.set_next_node(next_node);
	actual_bogie_name = node.get_bogie().get_name();
	actual_bogie_available_seats = node.get_bogie().get_available_seats();
	actual_bogie_max_capacity = node.get_bogie().get_max_capacity();
	actual_next_node_bogie_name = node.get_next_node()->get_bogie().get_name();
	actual_next_node_bogie_available_seats = node.get_next_node()->get_bogie().get_available_seats();
	actual_next_node_bogie_max_capacity = node.get_next_node()->get_bogie().get_max_capacity();
	actual_next_node_next_node = node.get_next_node()->get_next_node();
	// ASSERT
	QCOMPARE(actual_bogie_name, expected_bogie_name);
	QCOMPARE(actual_bogie_available_seats, expected_bogie_available_seats);
	QCOMPARE(actual_bogie_max_capacity, expected_bogie_max_capacity);
	QCOMPARE(actual_next_node_bogie_name, expected_next_node_bogie_name);
	QCOMPARE(actual_next_node_bogie_available_seats, expected_next_node_bogie_available_seats);
	QCOMPARE(actual_next_node_bogie_max_capacity, expected_next_node_bogie_max_capacity);
	QCOMPARE(actual_next_node_next_node, expected_next_node_next_node);
	delete next_node;
}

QTEST_APPLESS_MAIN(TestNode)

#include "tst_node.moc"
