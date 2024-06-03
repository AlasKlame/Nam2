    string line, luongcungStr;
        getline(inputFile, line);
        
        string hoahongStr;
        getline(inputFile, mataixe, ',');
        getline(inputFile, luongcungStr, ',');
        luongCung = stoi(luongcungStr);
        getline(inputFile, hoahongStr, '%'); // Đọc chuỗi cho đến khi gặp %
        hoahong = stof(hoahongStr) / 100;  // Chuyển đổi phần trăm
        inputFile.ignore(1);  // Bỏ qua dấu phẩy
        inputFile >> doanhthu;
            
        stringstream ss(line);
        string ngaykihopdongStr;
        getline(ss, ngaykihopdongStr, ',');
        stringstream ngayss(ngaykihopdongStr);
        int ngay, thang, nam;
        ngayss >> ngay;
        ngayss >> thang;
        ngayss >> nam;
        ngaykihopdong.setNgay(ngay);
        ngaykihopdong.setThang(thang);
        ngaykihopdong.setNam(nam);
    }