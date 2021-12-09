#include <QtTest>

#include "member.h"

class TestMember : public QObject {
	Q_OBJECT
	public:
		TestMember(void);
		~TestMember();
	private slots:
		void test_create_member(void);
};

TestMember::TestMember(void) { }

TestMember::~TestMember() { }

void TestMember::test_create_member(void) {
	// ARRANGE
	const Member member { "Samuel", "Hayden" };
	const std::string expected_first_name = "Samuel";
	const std::string expected_last_name = "Hayden";
	std::string actual_first_name;
	std::string actual_last_name;
	// ACT
	actual_first_name = member.get_first_name();
	actual_last_name = member.get_last_name();
	// ASSERT
	QCOMPARE(actual_first_name, expected_first_name);
	QCOMPARE(actual_last_name, expected_last_name);
}

QTEST_APPLESS_MAIN(TestMember)

#include "tst_member.moc"
