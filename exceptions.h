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
	 * @brief a base class for queue exceptions
	 */
	class QueueException: public DataStructureException {
	protected:
		explicit QueueException (const std::string &msg) : DataStructureException (msg) {}
		explicit QueueException (const char *msg) : DataStructureException (msg) {}
	};

	/**
	 * @brief thrown when trying to access an empty queue in an invalid manner
	 */
	class QueueIsEmpty: public QueueException {
	public:
		explicit QueueIsEmpty() : QueueException ("Queue is empty") {}
	};
}

#endif
