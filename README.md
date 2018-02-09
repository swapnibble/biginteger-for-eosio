# BigInteger for EOS.IO

BigInteger library for EOS Smart Contract

# Table of contents
- [What is this?](#what_is_this)
- [Original author](#original_author)
- [Example](#example)
- [Operators](#operators)
- [Build](#build)

<a name="what_is_this"></a>
You can use this library in a EOS Smart contract to do arithmetic without any precision limit.

This library has been tested on EOS.IO DAWN 2.x .
See [EOSIO github](https://github.com/EOSIO/eos).

<a name="original_author"></a>
## Original author  
Matt McCutchen  ( [C++ Big Integer Library](https://mattmccutchen.net/bigint/) )

<a name="example"></a>
## Example  
<pre><code>
 #include "eoslib/print.hpp"  
 #include "BigIntegerLibrary.hpp"  
    
 BigInteger a = 65536;  
 print("a * a * a * a * a * a * a * a: ", ( a * a * a * a * a * a * a * a ) );  
</code></pre>
then, eosd prints 340282366920938463463374607431768211456.

<a name="operators"></a>
## Operators
<pre><code>
arithmetic : +, -, *, /, %, ++(pre, post), --(pre, post), +=, -=, *=, /=, %=, etc.. ( see header for more details )
bit : &amp;, |, ^, <<=, >>= , etc.. ( see header for more details ) 
</code></pre>

<a name="build"></a>
## Build
`eoscpp -o <wastOutput.wast> <yourContractSrc.cpp> eos_mem_wrapper.cpp BigInteger.cpp BigIntegerAlgorithms.cpp BigIntegerUtils.cpp BigUnsigned.cpp BigUnsignedInABase.cpp`

If linker complains about memory_heap variable, then change as followings:  

find `memory_heap` variable in `memory.hpp` ( eoslib )  
then, change :
<pre><code>
static memory_manager memory_heap;
</code></pre
