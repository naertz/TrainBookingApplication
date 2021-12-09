QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../Application

SOURCES +=  \
  ../../Application/customer.cpp \
  ../../Application/member.cpp \
  ../../Application/party_member.cpp \
  tst_customer.cpp
