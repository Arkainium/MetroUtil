#ifndef METROBOTICS_POSIXSERIAL_H
#define METROBOTICS_POSIXSERIAL_H
/************************************************************************/
/* This was developed by John Cummins at Brooklyn College under the     */
/* supervision of Professor Sklar.                                      */
/*                                                                      */
/* It was adopted into the MetroUtil library, and is currently          */
/* maintained by Mark Manashirov from Brooklyn College and the entire   */
/* MetroBotics team at CUNY.                                            */
/*                                                                      */
/* It is released under the copyleft understanding. That is, any one is */
/* free to use, and modify, any part of it so long as it continues to   */
/* carry this notice.                                                   */
/************************************************************************/

#include "Serial.h"
#include <string>
#include <termios.h> // needed for baud rate

namespace metrobotics
{

	/**
	 * \brief   POSIX implementation of the Serial interface
	 * \details A class of objects that simulate serial communication in a
	 *          Posix-compliant environment.
	 * \author  John Cummins
	 * \author  Mark Manashirov
	 */
	class PosixSerial : public Serial
	{
		public:
			PosixSerial(const char *devName, unsigned int baudRate);
			~PosixSerial();

			// Exceptions.
			class InvalidDeviceName {};
			class ConnectionFailure {};
			class WriteFailure {};
			class WriteTimeout {};
			class ReadFailure {};
			class ReadTimeout {};
			class NullPointer {};

			// Implement input capabilities.
			void flushInput();
			unsigned char getByte();
			void getBlock(unsigned char *buf, unsigned long nBytes);


			// Implement output capabilities.
			void flushOutput();
			void putByte(const unsigned char);
			void putBlock(const unsigned char *buf, unsigned long nBytes);

			// Class-specific capabailites.

			// Toggle class-wide debugging.
			static void debugging(bool);

			// Flush both input and output.
			void flush();

			/**
			 * \brief   Set a timeout (in milliseconds) for all I/O operations.
			 * \details A timeout of 0 (the default) may block I/O indefinitely.
			 */
			void timeout(unsigned int ms = 0);

			/**
			 * \brief   Get a whole line of input from the serial device.
			 * \details We define a line as a sequence of characters whose last character is the
			 *          first occurrence of the character specified by the delimiter argument.  For
			 *          example, if the delimiter is the newline character itself, then that will be
			 *          the last character in the line; in other words the delimiter is included as
			 *          part of the line.
			 */
			std::string getLine(char delimiter = '\n');

		private:
			// Disable copying and assignment for PosixSerial objects.
			PosixSerial(const PosixSerial&);
			PosixSerial& operator=(const PosixSerial&);

			// Establish (or re-establish) a connection.
			void connect();

			// Internal state members.
			bool mFunctional;
			std::string mDevName;
			int mDevFD; // Posix file descriptor corresponding to the serial device
			unsigned int mLineSpeed; // Baud rate
			unsigned int mTimeOut; // in milliseconds
	};

}

#endif
