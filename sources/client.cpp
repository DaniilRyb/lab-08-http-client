// Copyright 2020 Your Name <your_email>

#include "client.hpp"

client::client(int argc, char* argv[]) : argc_(argc), argv_(argv) {}

int client::Run() {
  if (argc_ != 3) {
    std::cerr << "Usage: http-client-sync <url> "
                 "<request>\n"
              << " For Example:\n"
              << "    ./cmake-build-debug/tests  "
                 "http://localhost:8080/v1/api/suggest "
              << R"({\"input\":\"<user__input>\"})"
                 "\n";
    return EXIT_FAILURE;
  }

  try {
    prepareCommandLine();

    net::io_context ioc;
    tcp::resolver resolver{ioc};
    beast::tcp_stream stream(ioc);

    auto const results = resolver.resolve(parametrs.host, parametrs.port);
    stream.connect(results);

    http::string_body::value_type body = parametrs.request_body;

    http::request<http::string_body> req{http::verb::post, parametrs.target,
                                         parametrs.version};
    req.set(http::field::host, parametrs.host);
    req.body() = body;
    req.prepare_payload();
    req.set(http::field::content_type, "text/plain");

    http::write(stream, req);

    boost::beast::flat_buffer buffer;

    http::response<http::string_body> res;

    http::read(stream, buffer, res);
    std::cout << res.body() << std::endl;

    beast::error_code ec;
    stream.socket().shutdown(tcp::socket::shutdown_both, ec);

    if (ec && ec != beast::errc::not_connected) {
      throw beast::system_error{ec};
    }
  } catch (std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void client::prepareCommandLine() {
  URL url(argv_[1]);
  parametrs.url = url.parseUrl();
  parametrs.host = url.parseUrlToHost();
  parametrs.port = url.parseUrlToPort();
  parametrs.target = url.parseUrlToTarget();
  parametrs.request_body = argv_[2];
  parametrs.version = 11;
}