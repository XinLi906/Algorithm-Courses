#include <iostream>
#include "test.h"
using namespace std;

test bar(test param) {
    return test(10);
}

int main() {

    // this does NOT create a test object; instead, it creates a function
    // called a() that has no body (and thus C++ defaults it to return
    // 1).  Note that there is no output statement from the default
    // constructor.
    test a();
    cout << "attempted to create a: " << a << endl;
    // output:
    // attempted to create a: 1

    // this does  create a test object, calling  the default constructor.
    // Since  putting parenthesis in  there for  creating an  object and
    // calling  the  default  constructor  has another  meaning  in  C++
    // (specifically,  creating  a  function),   we  have  to  omit  the
    // parenthesis.
    cout << "----------------------------------------" << endl;
    test aa;
    cout << "created aa: " << aa << endl;
    // output:
    // ----------------------------------------
    // calling test(); object created is test[id=0,v=0]; address is 0xff852a50
    // created aa: test[id=0,v=0]

    // this creates a test object, calling the specific constructor that
    // takes in a single int value
    cout << "----------------------------------------" << endl;
    test b(1);
    cout << "created b: " << b << endl;
    // output:
    // ----------------------------------------
    // calling test(1); object created is test[id=1,v=1]; address is 0xff852a48
    // created b: test[id=1,v=1]

    // this creates two test objects via pointers and new
    cout << "----------------------------------------" << endl;
    test *c = new test(2);
    cout << "created *c: " << *c << " at " << c << endl;
    test *d = new test;
    cout << "created *d: " << *d << " at " << d << endl;
    // output:
    // ----------------------------------------
    // calling test(2); object created is test[id=2,v=2]; address is 0xa009008
    // created *c: test[id=2,v=2] at 0xa009008
    // calling test(); object created is test[id=3,v=0]; address is 0xa009018
    // created *d: test[id=3,v=0] at 0xa009018

    // subroutine invocation.  The copy constructor is invoked when the
    // actual parameter is copied into the formal parameter.  The
    // subroutine then creates test[id=4,v=10].  The parameter that was
    // copied into the subroutine (via the copy constructor) is then
    // destructed upon termination of the subroutine.
    cout << "----------------------------------------" << endl;
    cout << "about to invoke subroutine..." << endl;
    test e = bar(*c);
    cout << "finished invoking subroutine..." << endl;
    // output:
    // ----------------------------------------
    // about to invoke subroutine...
    // calling test(const test&) on test[id=2,v=2]; address is 0xff852a38
    // calling test(10); object created is test[id=4,v=10]; address is 0xff852a40
    // calling ~test() on test[id=2,v=2]
    // finished invoking subroutine...

    // because this assignment happens in the same statement as the
    // declaration, it invokes the copy constructor
    cout << "----------------------------------------" << endl;
    test f = b;
    // output:
    // ----------------------------------------
    // calling test(&test) on test[id=1,v=1]; address is 0xff852a30

    // we are only deleting one of the dynamically created test objects
    cout << "----------------------------------------" << endl;
    cout << "about to delete a test object..." << endl;
    delete c;
    // output:
    // ----------------------------------------
    // about to delete a test object...
    // calling ~test() on test[id=2,v=2]

    // because this assignment does NOT happen in the same statement as
    // the declaration, the operator=() subroutine is called.
    cout << "----------------------------------------" << endl;
    cout << "assignment..." << endl;
    aa = b;
    // output:
    // ----------------------------------------
    // assignment...
    // calling operator=(test[id=1,v=1])
    // calling test(&test) on test[id=1,v=1]; address is 0xa009008

    // upon termination of the main() function, all statically created
    // test objects are deallocated.
    cout << "----------------------------------------" << endl;
    cout << "about to leave main..." << endl;
    // output:
    // ----------------------------------------
    // about to leave main...
    // calling ~test() on test[id=1,v=1]
    // calling ~test() on test[id=4,v=10]
    // calling ~test() on test[id=1,v=1]
    // calling ~test() on test[id=0,v=0]

    // Note that d was created via dynamic memory allocation, so it is
    // not deallcoated by the program.  The operating system will clean
    // up the used memory, but it does not call the destructor on d.
}