#include<iostream> 
#include<ctime> 
#include<string> 
#include <boost/lexical_cast.hpp>                                   
#include <boost/asio.hpp>  
#include <boost/enable_shared_from_this.hpp>     
#include<boost/bind.hpp>  
#include <boost/shared_ptr.hpp> 
#include <boost/array.hpp> 
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <sstream> 
#include <vector> 
#include<iterator>
#include<boost/asio/post.hpp>
#include<boost/asio/thread_pool.hpp>
#include <boost/asio/io_service.hpp>
#include <queue>
#include <boost/thread/thread.hpp>
#include <boost/container/vector.hpp>
using  boost::asio::ip::tcp;
class HttpServer;
class Request :public boost::enable_shared_from_this<Request>
{
	HttpServer& server;
	boost::asio::streambuf request;
	boost::asio::streambuf response;
		void afterRead(const boost::system::error_code& ec, std::size_t bytes_transferred)
        {
		boost::asio::streambuf::const_buffers_type bufs = request.data();
		std::string str(boost::asio::buffers_begin(bufs),
			boost::asio::buffers_begin(bufs) + bufs.size());
		std::cout << str;
		std::string::size_type n2{};
		std::string::size_type n{};
		n = str.find("POST");
		if (n2 == str.find("GET"))
		{
			std::string delimiter = " ";
			size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			std::string token;
			std::vector<std::string>res;
			std::string strk;
			while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
				token = str.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;
				res.push_back(token);
			}
			res.push_back(str.substr(pos_start));
			std::vector<std::string> v = res;
			for (auto i : v) std::cout << i << std::endl;
			v.erase(v.begin(), v.begin() + 1);
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			for (unsigned i = 0; i < v.size(); ++i)
				std::cout << ' ' << v[i];
			std::cout << '\n';
			strk = v[0].substr(16, 10);			
			std::string delimiter1 = ",";
			size_t pos_start1 = 0, pos_end1, delim_len1 = delimiter1.length();
			std::string token1;
			std::vector<std::string> res1;
			std::string strk1;
			while ((pos_end1 = strk.find(delimiter1, pos_start1)) != std::string::npos) {
				token1 = strk.substr(pos_start1, pos_end1 - pos_start1);
				pos_start1 = pos_end1 + delim_len1;
				res1.push_back(token1);
			}
			res1.push_back(strk.substr(pos_start1));
			std::vector<std::string> v2 = res1;
			for (unsigned i = 0; i < v2.size(); ++i)
				std::cout << v2[i];
			std::cout << '\n';
			std::string& element1 = v2[0];
			long long element3 = stoi(element1);
			std::string& element2 = v2[1];
			long long element4 = stoi(element2);
			long long sq1 = 1;
			for (int i = 0; i < element4; i++)
			{
				sq1 *= element3;
			}
			std::string degree1;
			degree1 = boost::lexical_cast<std::string>(sq1);
			std::ostream res_stream(&response);
			std::string degree = { "very good" };
			res_stream << "HTTP/1.0 200 OK\r\n"
				<< "Content-Type: text/html; charset=UTF-8\r\n"
				<< "Content-Length: " << degree1.length() + 1 << "\r\n\r\n"
				<< degree1 << "\r\n\r\n";
			boost::asio::async_write(*socket, response, boost::bind(&Request::afterWrite, shared_from_this(), _1, _2));
		}
		 if (n2 != str.find("GET")) {
			std::string delimiter = " ";
			size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			std::string token;
			std::vector<std::string>res;
			std::string strk;
			while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
				token = str.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;
				res.push_back(token);
			}
			res.push_back(str.substr(pos_start));
			std::vector<std::string> v4 = res;
			for (auto i : v4) std::cout << i << std::endl;
			v4.erase(v4.begin(), v4.begin() + 1);
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			v4.pop_back();
			for (unsigned i = 0; i < v4.size(); ++i)
				std::cout << ' ' << v4[i];
			std::cout << '\n';
			strk = v4[0].substr(16, 10);
			std::string delimiter1 = ",";
			size_t pos_start1 = 0, pos_end1, delim_len1 = delimiter1.length();
			std::string token1;
			std::vector<std::string> res1;
			std::string strk1;
			while ((pos_end1 = strk.find(delimiter1, pos_start1)) != std::string::npos) {
				token1 = strk.substr(pos_start1, pos_end1 - pos_start1);
				pos_start1 = pos_end1 + delim_len1;
				res1.push_back(token1);
			}
			res1.push_back(strk.substr(pos_start1));
			std::vector<std::string> v5 = res1;
			for (unsigned i = 0; i < v5.size(); ++i)
				std::cout << v5[i];
			std::cout << '\n';
			std::string& elements1 = v5[0];
			std::cout << "okeys1 " << elements1.size() << std::endl;
			long long elements3 = stoi(elements1);
			std::string& elements2 = v5[1];
			long long elements4 = stoi(elements2);
			long long sq2 = 1;
			for (int i = 0; i < elements4; i++)
			{
				sq2 *= elements3;
			}
			std::string degree2;
			degree2 = boost::lexical_cast<std::string>(sq2);
			std::ostream res_stream(&response);
			std::string degree = { "very good" };
			res_stream << "HTTP/1.0 200 OK\r\n"
				<< "Content-Type: text/html; charset=UTF-8\r\n"
				<< "Content-Length: " << degree2.length() + 1 << "\r\n\r\n"
				<< degree2 << "\r\n\r\n";
			boost::asio::async_write(*socket, response, boost::bind(&Request::afterWrite, shared_from_this(), _1, _2));
		 }
		else
			std::cout <<std::endl;
	    }
	void afterWrite(const boost::system::error_code& ec, std::size_t bytes_transferred)
	{
		socket->close();
	}
public:
	boost::shared_ptr<tcp::socket>socket;
	Request(HttpServer& server);
	void answer()
	{
		if (!socket)return;
		boost::asio::async_read_until(*socket, request, "\r\n\r\n",
			boost::bind(&Request::afterRead, shared_from_this(), _1, _2));
	}
};
class RequestTwo :public boost::enable_shared_from_this<RequestTwo>
{
	HttpServer& server;
	boost::asio::streambuf requestTwo;
	boost::asio::streambuf responseTwo;
	void afterReadTwo(const boost::system::error_code& ec, std::size_t bytes_transferred)
	{
		boost::asio::streambuf::const_buffers_type bufsTwo = requestTwo.data();
		std::string strTwo(boost::asio::buffers_begin(bufsTwo),
			boost::asio::buffers_begin(bufsTwo) + bufsTwo.size());
		std::cout << strTwo;
		std::string::size_type n2{};
		std::string::size_type n{};
		std::string::size_type n1{};
		n = strTwo.find("POST");
		n1 == strTwo.find("average");
		if (n2 == strTwo.find("GET"))
		{
				std::string delimiter = " ";
				size_t pos_start = 0, pos_end, delim_len = delimiter.length();
				std::string token;
				std::vector<std::string>res;
				std::string strk;
				while ((pos_end = strTwo.find(delimiter, pos_start)) != std::string::npos) {
					token = strTwo.substr(pos_start, pos_end - pos_start);
					pos_start = pos_end + delim_len;
					res.push_back(token);
				}
				res.push_back(strTwo.substr(pos_start));
				std::vector<std::string> v4 = res;
				for (auto i : v4) std::cout << i << std::endl;
				v4.erase(v4.begin(), v4.begin() + 1);
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				v4.pop_back();
				for (unsigned i = 0; i < v4.size(); ++i)
					std::cout << ' ' << v4[i];
				std::cout << '\n';
				strk = v4[0].substr(31, 10);				
				std::vector<std::string> v5;
							v5.push_back(strk);

							std::string& elements1 = v5[0];
							std::cout << "okeys1 " << elements1.size() << std::endl;
							int elements3 = stoi(elements1);
							double sq2 = 0;
							double sq3 = 0;
							double sq4 = 0;
							std::cout << std::endl;

							for (int i = elements3; i <= 1000; i++)
							{
								sq2 += i;
								sq3 = sq2 / 1000.;
							}						
							std::string degree2;
							degree2 = boost::lexical_cast<std::string>(sq3);
							std::ostream res_stream(&responseTwo);
							std::string degree = { "very good" };
							res_stream << "HTTP/1.0 200 OK\r\n"
								<< "Content-Type: text/html; charset=UTF-8\r\n"
								<< "Content-Length: " << degree2.length() + 2 << "\r\n\r\n"
								<< degree2 << "\r\n\r\n";
						boost::asio::async_write(*socketTwo, responseTwo, boost::bind(&RequestTwo::afterWriteTwo, shared_from_this(), _1, _2));
		}
		else
			std::cout << std::endl;
		if (n2 != strTwo.find("GET"))
			{				
					std::string delimiter = " ";
					size_t pos_start = 0, pos_end, delim_len = delimiter.length();
					std::string token;
					std::vector<std::string>res;
					std::string strk;					
					while ((pos_end = strTwo.find(delimiter, pos_start)) != std::string::npos) {
						token = strTwo.substr(pos_start, pos_end - pos_start);
						pos_start = pos_end + delim_len;
						res.push_back(token);
					}
					res.push_back(strTwo.substr(pos_start));
					std::vector<std::string> v4 = res;
					for (auto i : v4) std::cout << i << std::endl;
					v4.erase(v4.begin(), v4.begin() + 1);
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();
					v4.pop_back();				
					for (unsigned i = 0; i < v4.size(); ++i)
						std::cout << ' ' << v4[i];
					std::cout << '\n';
		strk = v4[0].substr(31, 10);
		std::vector<std::string> v5;
		v5.push_back(strk);
		std::string& elements1 = v5[0];
		std::cout << "okeys1 " << elements1.size() << std::endl;
		int elements3 = stoi(elements1);

		double sq2 = 0;
		double sq3 = 0;
		double sq4 = 0;
		std::cout << std::endl;

		for (int i = elements3; i <= 1000; i++)
		{
			sq2 += i;
			sq3 = sq2 / 1000.;
		}
		std::string degree2;
		degree2 = boost::lexical_cast<std::string>(sq3);
		std::ostream res_stream(&responseTwo);
		std::string degree = { "very good" };
		res_stream << "HTTP/1.0 200 OK\r\n"
			<< "Content-Type: text/html; charset=UTF-8\r\n"
			<< "Content-Length: " << degree2.length() + 1 << "\r\n\r\n"
			<< degree2 << "\r\n\r\n";
		boost::asio::async_write(*socketTwo, responseTwo, boost::bind(&RequestTwo::afterWriteTwo, shared_from_this(), _1, _2));
		}
		else
			std::cout << std::endl;
	}
	void afterWriteTwo(const boost::system::error_code& ec, std::size_t bytes_transferred)
	{
		socketTwo->close();
	}
public:
	boost::shared_ptr<tcp::socket>socketTwo;
	RequestTwo(HttpServer& server);
	void answerTwo()
	{
		if (!socketTwo)return;
		boost::asio::async_read_until(*socketTwo, requestTwo, "\r\n\r\n",
			boost::bind(&RequestTwo::afterReadTwo, shared_from_this(), _1, _2));
	}
};
 class HttpServer
{
public:	
	HttpServer(unsigned int port) :  acceptor(io_service, tcp::endpoint(tcp::v4(), port)) {  }
	~HttpServer() {
		if (sThread)
		  threadPool_.join();
		if (sThread2)
		  threadPool_.join();
	}

	void Run()
	{		
		boost::system::error_code error_code{};
		size_t index{2};		
			boost::asio::post(threadPool_, [this] {sThread.reset(new std::thread(boost::bind(&HttpServer::thread_main, this))); });
			boost::asio::post(threadPool_, [this] {sThread2.reset(new std::thread(boost::bind(&HttpServer::thread_main, this))); });
			std::cout << " ";
	}
	void thread_main()
	{
		start_accept();
		io_service.run();
	}	
	boost::asio::io_service io_service;
	boost::asio::thread_pool threadPool_{5};
private:
	tcp::acceptor acceptor;
	boost::shared_ptr<std::thread> sThread;
	boost::shared_ptr<std::thread> sThread2;
	void start_accept()
	{	
		boost::shared_ptr<Request> req(new Request(*this));
		boost::shared_ptr<RequestTwo> req2(new RequestTwo(*this));
		acceptor.is_open();
		acceptor.async_accept(*req->socket,
			boost::bind(&HttpServer::handle_accept, this, req, _1));
		std::this_thread::sleep_for(std::chrono::milliseconds{ 1000});
		acceptor.async_accept(*req2->socketTwo,boost::bind(&HttpServer::handle_accept2, this, req2, _1));
	}
	void handle_accept(boost::shared_ptr<Request> req, const boost::system::error_code& error)
	{
		if (!error) { req->answer(); }
		start_accept();
	}
	void handle_accept2(boost::shared_ptr<RequestTwo> req, const boost::system::error_code& error)
	{
		if (!error) { req->answerTwo(); }
		start_accept();
	}
};
Request::Request(HttpServer& server) : server(server)
{
	socket.reset(new tcp::socket(server.io_service));
}
RequestTwo::RequestTwo(HttpServer& server) : server(server)
{
	socketTwo.reset(new tcp::socket(server.io_service));
} 

int main(int argc, char* argv[])
{
	HttpServer server(8080);
	server.Run();
	while (true)
	{

	}
}


	




	

















