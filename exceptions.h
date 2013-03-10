#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <exception>
#include <string>
using std::exception;
using std::string;

namespace DataStructures {

	class DataStructureException: exception {
		const string msg;
	protected:
		explicit DataStructureException (const char *msg) : DataStructureException (string (msg)) {}
		explicit DataStructureException (const string &msg) : exception(), msg (msg) {}
	public:
		virtual const char *what() const noexcept override {
		    return msg.data();
		}
	};

	/**
	 * @brief thrown when trying to access an element in an empty data structure
	 */
	class Empty: public DataStructureException {
	public:
		explicit Empty() : DataStructureException ("Empty set") {}
	};

	/**
	 * @brief thrown when trying to access an invalid index
	 */
	class OutOfBounds: public DataStructureException {
	public:
		explicit OutOfBounds () : DataStructureException ("Out of Bounds") {}
	};

	/**
	 * @brief thrown when trying to remove a non-existent element from a set
	 */
	class ElementDoesNotExist: public DataStructureException {
	public:
		explicit ElementDoesNotExist() : DataStructureException ("Element Does Not Exist") {}
	};
}

#endif
