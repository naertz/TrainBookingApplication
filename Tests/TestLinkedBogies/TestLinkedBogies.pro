QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../Application

SOURCES +=  \
  ../../Application/bogie.cpp \
  ../../Application/customer.cpp \
  ../../Application/linked_bogies.cpp \
  ../../Application/linked_bogies_empty_exception.cpp \
  ../../Application/linked_bogies_insufficient_capacity_exception.cpp \
  ../../Application/linked_bogies_invalid_argument_exception.cpp \
  ../../Application/linked_bogies_out_of_range_exception.cpp \
  ../../Application/member.cpp \
  ../../Application/node.cpp \
  ../../Application/party_member.cpp \
  tst_linked_bogies.cpp
