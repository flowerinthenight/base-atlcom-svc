# Overview

Skeleton code for an ATL-based Windows service. Basically the same as a [traditional Windows service](https://github.com/flowerinthenight/win32-base-service) but with some advantages.

* Can be started on-demand by the first client call (via COM).
* Clients can call service functions with parameters and return values using COM. In traditional services, clients normally communicates using service control codes and you need some kind of IPC (named pipes, shared memory, etc.) for bi-directional data exchange.

# License

[The MIT License](./LICENSE.md)
