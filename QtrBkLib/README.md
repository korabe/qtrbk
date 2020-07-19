# Korabe QtrBk (pronounced Quarterback)

## Synopsis

Despite the QuickBooks SDK, connection to QuickBooks from a web application has been notoriously difficult. Here are some reasons why:

1. Using common web application languages such as PHP, Javascript, Ruby, Python, there has been no easy way to connect directly to QuickBooks. 
1. The QuickBooks remote connector relies on a queueing system

Quarterback solves this problem for languages with a [foreign function interface](https://en.wikipedia.org/wiki/Foreign_function_interface). Quarterback is a library that exports functions that can then be accessed through the language's forign function interface.

### Build

As of yet there are no special build instructions.

### Configure

To make the QtrBk.dll library available to your PHP web application, the dll path must be accessible through the `PATH` environment variable.

### Components of a QuickBooks request via QtrBk

#### QtrBk.Request

The request is comprised of XML, and QBXML to be more exact. 