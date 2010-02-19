#ifndef METROBOTICS_SERIAL_H
#define METROBOTICS_SERIAL_H
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

namespace metrobotics
{

	/**
	 * \brief   User-defined data error exception
	 * \details An exception class (throw me!).
	 * \author  John Cummins
	 */
	class DataError
	{
		public:
			DataError(int id)    { mId = id; }
			operator int() const { return mId; }
			int       id() const { return mId; }
		private:
			int mId;
	};

	/**
	 * \brief   Sequential input device (source of input)
	 * \details A purely abstract class of objects that supply data.
	 * \author  John Cummins
	 */
	class DataSource
	{
		public:
			DataSource() {}
			virtual ~DataSource() {}
			virtual unsigned char getByte() = 0;
			virtual void getBlock(unsigned char *buf, unsigned long nBytes) = 0;
	};

	/**
	 * \brief   Sequential output device (destination of output)
	 * \details A purely abstract class of objects that consume data.
	 * \author  John Cummins
	 */
	class DataSink
	{
		public:
			DataSink() {}
			virtual ~DataSink() {}
			virtual void putByte(const unsigned char) = 0;
			virtual void putBlock(const unsigned char *buf, unsigned long nBytes) = 0;
	};

	/**
	 * \brief   A virtual serial device capable of sequential input and output
	 * \details A purely abstract class of objects that simulate serial
	 *          communication; observe that Serial is both a DataSource and
	 *          a DataSink.
	 * \author  John Cummins
	 */
	class Serial : public DataSource, public DataSink
	{
		public:
			Serial() {}
			virtual ~Serial() {}

			// [Input capabilities.]
			virtual void flushInput() = 0;
			virtual unsigned char getByte() = 0;
			virtual void getBlock(unsigned char *buf, unsigned long nBytes) = 0;

			// [Output capabilities.]
			virtual void flushOutput() = 0;
			virtual void putByte(const unsigned char) = 0;
			virtual void putBlock(const unsigned char *buf, unsigned long nBytes) = 0;
	};

}

#endif
