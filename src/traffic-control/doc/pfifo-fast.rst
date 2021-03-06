.. include:: replace.txt
.. highlight:: cpp

pfifo_fast queue disc
---------------------

Model Description
*****************

Linux pfifo_fast is the default priority queue enabled on Linux
systems. Packets are enqueued in three priority bands (implemented
as FIFO droptail queues) based on their priority (users can read
:ref:`Socket-options` for details on how to set packet priority).
The four least significant bits of the priority are used to determine
the selected band according to the following table:

==============  ======
Priority & 0xf  Band
==============  ======
    0            1
    1            2
    2            2
    3            2
    4            1
    5            2
    6            0
    7            0
    8            1
    9            1
   10            1
   11            1
   12            1
   13            1
   14            1
   15            1
==============  ======

The system behaves similar to three ns3::DropTail queues operating
together, in which packets from higher priority bands are always
dequeued before a packet from a lower priority band is dequeued.

The queue disc capacity, i.e., the maximum number of packets that can
be enqueued in the queue disc, is set through the limit attribute, which
plays the same role as txqueuelen in Linux. If no internal queue is
provided, three DropTail queues having each a capacity equal to limit are
created by default. User is allowed to provide queues, but they must be
three, operate in packet mode and each have a capacity not less
than limit. No packet filter can be added to a PfifoFastQueueDisc.


Attributes
==========

The PfifoFastQueueDisc class holds a single attribute:

* ``Limit:`` The maximum number of packets accepted by the queue disc. The default value is 1000.

Examples
========

The traffic-control example located in ``examples/traffic-control`` shows how to configure
and install a pfifo_fast queue on Ipv4 nodes.

Validation
**********

The pfifo_fast model is tested using :cpp:class:`PfifoFastQueueDiscTestSuite` class defined
in ``src/traffic-control/test/pfifo-fast-queue-disc-test-suite.cc``. The suite includes 4 test cases:

* Test 1: The first test checks whether IPv4 packets are enqueued in the correct band based on the TOS byte
* Test 2: The second test checks whether IPv4 packets are enqueued in the correct band based on the TOS byte
* Test 3: The third test checks that the queue disc cannot enqueue more packets than its limit
* Test 4: The fourth test checks that packets that the filters have not been able to classify are enqueued into the default band of 1
