#include "List.h"

List::List() {}

List::List(const List& source):
    head(source.head), tail(source.head), count(source.count) {}

List::~List() 