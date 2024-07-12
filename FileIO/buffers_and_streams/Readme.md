# Buffers and Streams

Steams are sources of data from where data can be read from or written to.

Buffers are TEMPORARY spaces in memory where data is stored temporarily while being written
to a stream. Since direct I/O at streams is time consuming, the cpu create buffers in the
memory and write data there for some time instead of writing it directly to the stream.
When the buffer fills up, that data from buffer is written to the stream at once, thus
reducing the number of consecutive write operations. That's why it's important to FLUSH
the buffer BEFORE CLOSING a stream, because all data stored in the buffer might not have
been written to the file. The `fclose` function in C automatically flushes the buffer
before closing a file stream. But, we can flush manually using `fflush` if we want.
