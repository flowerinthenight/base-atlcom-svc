# Overview

Skeleton code for an ATL-based Windows service. Basically the same as a [traditional Windows service](https://github.com/flowerinthenight/win32-base-service) but with some advantages.

* Can be started on-demand by the first client call (via COM).
* Clients can call service functions with parameters and return values using COM. In traditional services, clients normally communicates using service control codes and you need some kind of IPC (named pipes, shared memory, etc.) for bi-directional data exchange.

### Installation

Run the following in an elevated command prompt.

```
BaseAtlComSvc.exe /service
```

This will install the service with a "Manual" startup type. You can start the service manually or by command prompt or from a client app.

### Uninstallation

```
BaseAtlComSvc.exe /unregserver
```

### ETW trace

This project uses the ETW setup [here](https://github.com/flowerinthenight/win32-etw-manifest).

# License

[The MIT License](./LICENSE.md)
