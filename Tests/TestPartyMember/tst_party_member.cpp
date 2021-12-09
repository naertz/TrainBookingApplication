#include <QtTest>

#include "party_member.h"

class TestPartyMember : public QObject {
	Q_OBJECT
	public:
		TestPartyMember(void);
		~TestPartyMember();
	private slots:
		void test_create_party_member(void);
};

TestPartyMember::TestPartyMember(void) { }

TestPartyMember::~TestPartyMember() { }

void TestPartyMember::test_create_party_member(void) {
	// ARRANGE
	const PartyMember party_member { "Frodo", "Baggins", 22 };
	const std::string expected_first_name = "Frodo";
	const std::string expected_last_name = "Baggins";
	const int expected_age = 22;
	std::string actual_first_name;
	std::string actual_last_name;
	int actual_age;
	// ACT
	actual_first_name = party_member.get_first_name();
	actual_last_name = party_member.get_last_name();
	actual_age = party_member.get_age();
	// ASSERT
	QCOMPARE(actual_first_name, expected_first_name);
	QCOMPARE(actual_last_name, expected_last_name);
	QCOMPARE(actual_age, expected_age);
}

QTEST_APPLESS_MAIN(TestPartyMember)

#include "tst_party_member.moc"
