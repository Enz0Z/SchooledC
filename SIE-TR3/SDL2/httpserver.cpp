#include "headers.h"
#include <httpserver.hpp>

using namespace httpserver;

class xPos : public http_resource {
    public:
        const std::shared_ptr<http_response> render(const http_request& req) {
            setPosX(std::stoi(req.get_querystring().substr(2)));
            return std::shared_ptr<http_response>(new string_response("Setted xPos"));
        }
};

class yPos : public http_resource {
    public:
        const std::shared_ptr<http_response> render(const http_request& req) {
            setPosY(std::stoi(req.get_querystring().substr(2)));
            return std::shared_ptr<http_response>(new string_response("Setted yPos"));
        }
};

void startHost() {
    webserver ws = create_webserver(80);
    
    xPos xP;
    yPos yP;
    ws.register_resource("/x", &xP);
    ws.register_resource("/y", &yP);
    ws.start(false);
}
