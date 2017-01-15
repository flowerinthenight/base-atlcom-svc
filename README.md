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

### Using the test client

A client console app is provided to test the service. After the service is installed, run `testclient.exe` without arguments. This will query the service version (which is hardcoded to 1.0.0). The call will cause the service to start automatically (when it's not yet started).

### Testing service notification

The service can also notify clients of events via IDispatch. To test, run `testclient.exe event`. The client will send a value to the service and in return, the service will notify the client of the received value.

### Uninstallation

```
BaseAtlComSvc.exe /unregserver
```

### ETW trace

This project uses the ETW setup [here](https://github.com/flowerinthenight/win32-etw-manifest).

# License

[The MIT License](./LICENSE.md)
