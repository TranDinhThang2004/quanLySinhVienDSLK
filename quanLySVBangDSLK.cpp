#include <iostream>
#include <string>

using namespace std;

struct sinhVien
{
	string hoTen;
	int namSinh;
	struct sinhVien* next;	
};


sinhVien* themSinhVien(sinhVien* head, string hoten, int namsinh)
{
	sinhVien* sv = new sinhVien;
	sv->hoTen = hoten;
	sv->namSinh = namsinh;
	sv->next = NULL;
	if(head == NULL)
	{
		head = sv;
	}
	else
	{
		sinhVien* p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		 	p->next = sv;
	}
	return head;
}

sinhVien* xoaSinhVien(sinhVien* head, int m)
{
	if(head == NULL)
	{
		return NULL;
	}
	if(m==1)
	{
		sinhVien* p = head;
		head = head->next;
		delete p;
		
	}
	else
	{
		sinhVien* p = head;
		for(int i=1; i < m-1; i++)
		{
			if(p->next == NULL)
			{
				return head;
			}
			p = p->next;
		}
		if(p->next == NULL)
		{
			return head;
		}
		sinhVien* q = p->next;
		p->next = q->next;
		delete q;
	}
	return head;
}

void thayDoiThongTinNamSinh(sinhVien* head, int m, int n)
{
	sinhVien* p = head;
	for(int i = 1; i < m; i++)
	{
		if(p==NULL)
		{
			return;
		}
		p = p->next;
	}
	if(p != NULL)
	{
		p->namSinh = n ;
	}
}

void inSinhVienCoCungNamSinh(sinhVien* head, int n)
{
	sinhVien* p = head;
	while(p != NULL)
	{
		if(p->namSinh == n)
		{
			cout << p->hoTen << endl;
		}
		p = p->next;
	}
}

void giaiPhongBoNho(sinhVien* head)
{
	sinhVien* p = head;
	while (p != NULL)
	{
		sinhVien* q = p;
		p = p->next;
		delete q;
	}
}





int main() {
	sinhVien* head = NULL;
	while(1)
	{
		cout << "--------------------------" << endl;
		cout << "1. Nhap so luong SV muon Them\n";
		cout << "2. Hien Thi DS SV\n";
		cout << "3. Xoa 1 SV khoi DS\n";
		cout << "4. Thay doi nam sinh SV\n";
		cout << "5. Hien thi thong tin SV co cung nam sinh\n";
		cout << "6. Giai phong bo nho cua DSSV\n";
		cout << "7. Thoat\n";
		cout << "--------------------------" << endl;
		int lc; cout << "Nhap lua chon cua ban: "; cin >> lc;
		if(lc == 1)
		{
			
			    int n;
			    cout << "Nhap so sinh vien: ";
			    cin >> n;
			    for (int i = 1; i <= n; i++) 
				{
			        string hoten;
			        int namsinh;
			        cout << "Nhap thong tin sinh vien thu " << i << endl;
			        cout << "Ho ten: ";
			        cin.ignore();
			        getline(cin, hoten);
			        cout << "Nam sinh: ";
			        cin >> namsinh;
			        head = themSinhVien(head, hoten, namsinh);

				}
		}
		else
		if(lc == 2)
		{
			cout << "Danh sach sinh vien vua nhap:\n";
		    sinhVien* p = head;
		    while (p != NULL) 
			{
		        cout << p->hoTen << "\t" << p->namSinh << endl;
		        p = p->next;
			}
		}
		else
		if(lc == 3)
		{
		int m;
    		cout << "Nhap vi tri sinh vien can xoa: ";
   			cin >> m;
    		head = xoaSinhVien(head, m);

		    cout << "Danh sach sinh vien sau khi xoa:\n";
		    	sinhVien* p = head;
		    while (p != NULL) 
			{
		        cout << p->hoTen << "\t" << p->namSinh << endl;
		        p = p->next;
		    }
					
		}
		else
		if(lc == 4)
		{
			 int k, n;
		    	cout << "Nhap vi tri sinh vien can thay doi nam sinh: ";
		    	cin >> k;
		    	cout << "Nhap nam sinh moi: ";
		   		cin >> n;
		    thayDoiThongTinNamSinh(head, k, n);
		
		    	cout << "Danh sach sinh vien sau khi thay doi nam sinh:\n";
		   		sinhVien* p = head;
		    while (p != NULL) 
			{
		        cout << p->hoTen << "\t" << p->namSinh << endl;
		        p = p->next;
			}
		}
		else
		if(lc == 5)
		{
			int ns;
			    cout << "Nhap nam sinh muon tim kiem: ";
			    cin >> ns;
			    cout << "Danh sach sinh vien co nam sinh la " << ns << ":\n";
			    inSinhVienCoCungNamSinh(head, ns);
		}
		else
		if(lc == 6) 
		{
			giaiPhongBoNho(head);
		}
		else
		{
			break;
		}
	}
	return 0;
}
