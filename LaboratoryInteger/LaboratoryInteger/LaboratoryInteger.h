#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Integer {
public:
    Integer() { // конструктор с default values, равен 0
        number.resize(1);
        number[0] = 0;
    }
    Integer(string s) { // конструктор от строки
        if (s[0] == '-') {
            auto digit = s[1];
            number.push_back((digit - '0') * -1);
            for (int i = 2; i < s.size(); i++) {
                auto digit = s[i];
                number.push_back(digit - '0');
            }
        }
        else {
            for (int i = 0; i < s.size(); i++) {
                auto digit = s[i];
                number.push_back(digit - '0');
            }
        }
        reverse(number.begin(), number.end());
    }
    Integer(vector<int> number) { // конструктор от вектора
        this->number = number;
    }
    Integer(char unsigned s) {
        number.push_back(s - '0');
    }
    Integer(char s) {
        number.push_back(s - '0');
    }
    Integer(short unsigned number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        while (number) {
            this->number.push_back(number % base);
            number /= base;
        }
    }
    Integer(short number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        if (number < 0) {
            number *= -1;
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
            this->number.back() *= -1;
        }
        else {
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
        }
    }
    Integer(unsigned int number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        while (number) {
            this->number.push_back(number % base);
            number /= base;
        }
    }
    Integer(int number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        if (number < 0) {
            number *= -1;
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
            this->number.back() *= -1;
        }
        else {
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
        }
    }
    Integer(long unsigned number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        while (number) {
            this->number.push_back(number % base);
            number /= base;
        }
    }
    Integer(long number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        if (number < 0) {
            number *= -1;
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
            this->number.back() *= -1;
        }
        else {
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
        }
    }
    Integer(long long unsigned number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        while (number) {
            this->number.push_back(number % base);
            number /= base;
        }
    }
    Integer(long long number) {
        if (number == 0) {
            this->number.push_back(0);
        }
        if (number < 0) {
            number *= -1;
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
            this->number.back() *= -1;
        }
        else {
            while (number) {
                this->number.push_back(number % base);
                number /= base;
            }
        }
    }
    ~Integer() {
        number.clear();
    }
    // ВЫВОД
    void write() const {
        for (int i = number.size() - 1; i >= 0; i--) {
            auto digit = number[i];
            cout << digit;
        }
        cout << endl;
    }
    // УНАРНЫЕ ОПЕРАЦИИ -a, --a, a--, +a, ++a, a++;
    Integer operator - () const {
        Integer th_minus = *this;
        th_minus.number.back() *= -1;
        return th_minus;
    }
    Integer& operator -- () {
        *this = *this - Integer(one);
        return *this;
    }
    Integer operator -- (int) {
        Integer th_copy = *this;
        *this = *this - Integer(one);
        return th_copy;
    }
    Integer operator + () const {
        return *this;
    }
    Integer& operator ++ () {
        *this = *this + Integer(one);
        return *this;
    }
    Integer operator ++ (int) {
        Integer th_copy = *this;
        *this = *this + Integer(one);
        return th_copy;
    }
    // ОСНОВНЫЕ ОПЕРАЦИИ +, +=, -, -+, *, *=, /, /=, %, %=
    Integer operator + (const Integer& a) {
        if (this->number.back() < 0) {
            Integer th_no_minus = *this;
            Integer a_no_minus = a;
            th_no_minus.number.back() *= -1;
            if (a.number.back() < 0) {
                a_no_minus.number.back() *= -1;
                th_no_minus = th_no_minus + a_no_minus;
                th_no_minus.number.back() *= -1;
                return th_no_minus;
            }
            else {
                th_no_minus = a_no_minus - th_no_minus;
                return th_no_minus;
            }
        }
        else if (a.number.back() < 0) {
            Integer a_no_minus = a;
            Integer th_no_minus = *this;
            a_no_minus.number.back() *= -1;
            a_no_minus = th_no_minus - a_no_minus;
            return a_no_minus;
        }
        //оба положительные
        vector<int> result;
        int carry = 0;
        for (int i = 0; i < min(a.number.size(), this->number.size()); i++) {
            int cur_sum = carry + a.number[i] + this->number[i];
            result.push_back(cur_sum % 10);
            carry = cur_sum / 10;
        }
        for (size_t i = min(a.number.size(), this->number.size()); i < max(a.number.size(), this->number.size()); i++) {
            if (a.number.size() > this->number.size()) {
                int cur_sum = carry + a.number[i];
                result.push_back(cur_sum % 10);
                carry = cur_sum / 10;
            }
            else {
                int cur_sum = carry + this->number[i];
                result.push_back(cur_sum % 10);
                carry = cur_sum / 10;
            }
        }
        if (carry != 0) {
            result.push_back(carry);
        }
        Integer c(result);
        return c;
    }
    Integer& operator += (const Integer& a) {
        *this = *this + a;
        return *this;
    }
    Integer operator - (const Integer& a) {
        if (this->number.back() < 0) {
            Integer th_no_minus = *this;
            Integer a_no_minus = a;
            th_no_minus.number.back() *= -1;
            if (a.number.back() < 0) {
                a_no_minus.number.back() *= -1;
                th_no_minus = a_no_minus - th_no_minus;
                return th_no_minus;
            }
            else {
                th_no_minus = th_no_minus + a_no_minus;
                th_no_minus.number.back() *= -1;
                return th_no_minus;
            }
        }
        else if (a.number.back() < 0) {
            Integer a_no_minus = a;
            Integer th_no_minus = *this;
            a_no_minus.number.back() *= -1;
            a_no_minus = th_no_minus + a_no_minus;
            return a_no_minus;
        }
        //оба положительные
        vector<int> result;
        int carry = 0;
        if (*this == a) {
            return 0;
        }
        else if (*this > a) {
            for (int i = 0; i < a.number.size(); i++) {
                int cur_diff = this->number[i] - a.number[i] - carry;
                if (cur_diff < 0) {
                    cur_diff += 10;
                    carry = 1;
                }
                else {
                    carry = 0;
                }
                result.push_back(cur_diff);
            }
            for (size_t i = a.number.size(); i < this->number.size(); i++) {
                if (this->number[i] - carry < 0) {
                    result.push_back(this->number[i] + 10 - carry);
                    carry = 1;
                }
                else {
                    result.push_back(this->number[i] - carry);
                    carry = 0;
                }
            }
            while (!result.back() && result.size() > 1) {
                result.pop_back();
            }
            Integer c(result);
            return c;
        }
        else {
            for (int i = 0; i < this->number.size(); i++) {
                int cur_diff = a.number[i] - this->number[i] - carry;
                if (cur_diff < 0) {
                    cur_diff += 10;
                    carry = 1;
                }
                else {
                    carry = 0;
                }
                result.push_back(cur_diff);
            }
            for (size_t i = this->number.size(); i < a.number.size(); i++) {
                if (a.number[i] - carry < 0) {
                    result.push_back(a.number[i] + 10 - carry);
                    carry = 1;
                }
                else {
                    result.push_back(a.number[i] - carry);
                    carry = 0;
                }
            }
            while (!result.back() && result.size() > 1) {
                result.pop_back();
            }
            result.back() *= -1;
            Integer c(result);
            return c;
        }
    }
    Integer& operator -= (const Integer& a) {
        *this = *this - a;
        return *this;
    }
    Integer operator * (const Integer& a) {
        if (this->number.back() < 0) {
            Integer th_no_minus = *this;
            Integer a_no_minus = a;
            th_no_minus.number.back() *= -1;
            if (a.number.back() < 0) {
                a_no_minus.number.back() *= -1;
                th_no_minus = th_no_minus * a_no_minus;
                return th_no_minus;
            }
            else {
                th_no_minus = th_no_minus * a_no_minus;
                th_no_minus.number.back() *= -1;
                return th_no_minus;
            }
        }
        else if (a.number.back() < 0) {
            Integer a_no_minus = a;
            Integer th_no_minus = *this;
            a_no_minus.number.back() *= -1;
            a_no_minus = th_no_minus * a_no_minus;
            a_no_minus.number.back() *= -1;
            return a_no_minus;
        }
        //оба положительные
        vector<int> result(this->number.size() * a.number.size(), 0);
        if ((this->number.size() == 1) || (a.number.size() == 1)) {
            result.resize(this->number.size() * a.number.size() + 1, 0);
        }
        for (int i = 0; i < this->number.size(); i++) {
            int carry = 0;
            for (int j = 0; j < a.number.size(); j++) {
                int ij = i + j;
                int cur = result[ij] + this->number[i] * a.number[j] + carry;
                carry = cur / this->base;
                result[ij] = cur % this->base;
            }
            size_t cur = a.number.size();
            while (carry) {
                size_t icur = i + cur;
                result[icur] = carry % this->base;
                cur++;
                carry /= this->base;
            }
        }
        while (!result.back() && result.size() > 1) {
            result.pop_back();
        }
        Integer c(result);
        return c;
    }
    Integer& operator *= (const Integer& a) {
        *this = *this * a;
        return *this;
    }
    Integer operator / (const Integer& a) {
        try { //код, который может привести к ошибке, располагается тут
            if (a.number.back() == 0) {
                throw 123;
            }
        }
        catch (int i) { //сюда передастся int
            cout << "error" << i << " can't divide by zero" << endl;
        }
        if (this->number.back() < 0) {
            Integer th_no_minus = *this;
            Integer a_no_minus = a;
            th_no_minus.number.back() *= -1;
            if (a.number.back() < 0) {
                a_no_minus.number.back() *= -1;
                th_no_minus = th_no_minus / a_no_minus;
                return th_no_minus;
            }
            else {
                th_no_minus = th_no_minus / a_no_minus;
                th_no_minus.number.back() *= -1;
                return th_no_minus;
            }
        }
        else if (a.number.back() < 0) {
            Integer a_no_minus = a;
            Integer th_no_minus = *this;
            a_no_minus.number.back() *= -1;
            a_no_minus = th_no_minus / a_no_minus;
            a_no_minus.number.back() *= -1;
            return a_no_minus;
        }
        //оба положительные
        vector<int> result(this->number.size() - a.number.size() + 1, 0);
        Integer c(result);
        for (int i = result.size() - 1; i >= 0; i--) {
            while (c * a <= *this) {
                c.number[i]++;
            }
            c.number[i]--;
        }
        while (c.number.size() > 1 && !c.number.back()) {
            c.number.pop_back();
        }
        return c;
    }
    Integer& operator /= (const Integer& a) {
        *this = *this / a;
        return *this;
    }
    Integer operator % (const Integer& a) {
        Integer c;
        c = *this - (*this / a) * a;
        return c;
    }
    Integer& operator %= (const Integer& a) {
        *this = *this % a;
        return *this;
    }
    // ПЕРЕВОД В ДРУГИЕ ТИПЫ
    explicit operator bool() const {

    }
    explicit operator char unsigned() const {

    }
    explicit operator char() const {

    }
    explicit operator short unsigned() const {
        Integer th_type = *this;
        short unsigned c = 0;
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * short unsigned(pow(10, i - 1));
            th_type.number.pop_back();
        }
        return c;
    }
    explicit operator short() const {
        Integer th_type = *this;
        short c = 0;
        bool flag_minus = false;
        if (th_type.number.back() < 0) {
            flag_minus = true;
            th_type.number.back() *= -1;
        }
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * short(pow(10, i - 1));
            th_type.number.pop_back();
        }
        if (flag_minus == true) {
            c *= -1;
        }
        return c;
    }
    explicit operator int unsigned() const {
        Integer th_type = *this;
        int unsigned c = 0;
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * int unsigned(pow(10, i - 1));
            th_type.number.pop_back();
        }
        return c;
    }
    explicit operator int() const {
        Integer th_type = *this;
        int c = 0;
        bool flag_minus = false;
        if (th_type.number.back() < 0) {
            flag_minus = true;
            th_type.number.back() *= -1;
        }
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * int(pow(10, i - 1));
            th_type.number.pop_back();
        }
        if (flag_minus == true) {
            c *= -1;
        }
        return c;
    }
    explicit operator long unsigned() const {
        Integer th_type = *this;
        long unsigned c = 0;
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * long unsigned(pow(10, i - 1));
            th_type.number.pop_back();
        }
        return c;
    }
    explicit operator long() const {
        Integer th_type = *this;
        long c = 0;
        bool flag_minus = false;
        if (th_type.number.back() < 0) {
            flag_minus = true;
            th_type.number.back() *= -1;
        }
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * long(pow(10, i - 1));
            th_type.number.pop_back();
        }
        if (flag_minus == true) {
            c *= -1;
        }
        return c;
    }
    explicit operator long long unsigned() const {
        Integer th_type = *this;
        long long unsigned c = 0;
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * long long unsigned(pow(10, i - 1));
            th_type.number.pop_back();
        }
        return c;
    }
    explicit operator long long() const {
        Integer th_type = *this;
        long long c = 0;
        bool flag_minus = false;
        if (th_type.number.back() < 0) {
            flag_minus = true;
            th_type.number.back() *= -1;
        }
        for (size_t i = th_type.number.size(); i > 0; i--) {
            c += th_type.number.back() * long long(pow(10, i - 1));
            th_type.number.pop_back();
        }
        if (flag_minus == true) {
            c *= -1;
        }
        return c;
    }
    // БУЛЕВЫЕ ОПЕРАЦИИ ==; !=; <; <=; >; >=;
    bool operator == (const Integer& a) {
        if (this->number.back() < 0) {
            if (a.number.back() < 0) {
                Integer th_no_minus = *this;
                Integer a_no_minus = a;
                th_no_minus.number.back() *= -1;
                a_no_minus.number.back() *= -1;
                if (th_no_minus == a_no_minus) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else if (a.number.back() < 0) {
            return false;
        }
        //они оба положительные
        if (this->number.size() < a.number.size() || this->number.size() > a.number.size()) {
            return false;
        }
        else {
            for (int i = this->number.size() - 1; i >= 0; i--) {
                if (this->number[i] > a.number[i] || this->number[i] < a.number[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    bool operator != (const Integer& a) {
        if (*this == a) {
            return false;
        }
        else {
            return true;
        }
    }
    bool operator < (const Integer& a) {
        if (this->number.back() < 0) {
            if (a.number.back() < 0) {
                Integer th_no_minus = *this;
                Integer a_no_minus = a;
                th_no_minus.number.back() *= -1;
                a_no_minus.number.back() *= -1;
                if (th_no_minus < a_no_minus) {
                    return false;
                }
                else {
                    if (th_no_minus == a_no_minus) {
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
            else {
                return true;
            }
        }
        else if (a.number.back() < 0) {
            return false;
        }
        //они оба положительные
        if (this->number.size() < a.number.size()) {
            return true;
        }
        else if (this->number.size() > a.number.size()) {
            return false;
        }
        else {
            for (int i = this->number.size() - 1; i >= 0; i--) {
                if (this->number[i] > a.number[i]) {
                    return false;
                }
                if (this->number[i] < a.number[i]) {
                    return true;
                }
            }
            return false;
        }
    }
    bool operator <= (const Integer& a) {
        if (this->number.back() < 0) {
            if (a.number.back() < 0) {
                Integer th_no_minus = *this;
                Integer a_no_minus = a;
                th_no_minus.number.back() *= -1;
                a_no_minus.number.back() *= -1;
                if (th_no_minus <= a_no_minus) {
                    if (th_no_minus == a_no_minus) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return true;
                }
            }
            else {
                return true;
            }
        }
        else if (a.number.back() < 0) {
            return false;
        }
        //они оба положительные
        if (this->number.size() < a.number.size()) {
            return true;
        }
        else if (this->number.size() > a.number.size()) {
            return false;
        }
        else {
            for (int i = this->number.size() - 1; i >= 0; i--) {
                if (this->number[i] > a.number[i]) {
                    return false;
                }
                if (this->number[i] < a.number[i]) {
                    return true;
                }
            }
            return true;
        }
    }
    bool operator > (const Integer& a) {
        if (this->number.back() < 0) {
            if (a.number.back() < 0) {
                Integer th_no_minus = *this;
                Integer a_no_minus = a;
                th_no_minus.number.back() *= -1;
                a_no_minus.number.back() *= -1;
                if (th_no_minus > a_no_minus) {
                    return false;
                }
                else {
                    if (th_no_minus == a_no_minus) {
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
            else {
                return false;
            }
        }
        else if (a.number.back() < 0) {
            return true;
        }
        //они оба положительные
        if (this->number.size() < a.number.size()) {
            return false;
        }
        else if (this->number.size() > a.number.size()) {
            return true;
        }
        else {
            for (int i = this->number.size() - 1; i >= 0; i--) {
                if (this->number[i] > a.number[i]) {
                    return true;
                }
                if (this->number[i] < a.number[i]) {
                    return false;
                }
            }
            return false;
        }
    }
    bool operator >= (const Integer& a) {
        if (this->number.back() < 0) {
            if (a.number.back() < 0) {
                Integer th_no_minus = *this;
                Integer a_no_minus = a;
                th_no_minus.number.back() *= -1;
                a_no_minus.number.back() *= -1;
                if (th_no_minus >= a_no_minus) {
                    if (th_no_minus == a_no_minus) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        else if (a.number.back() < 0) {
            return true;
        }
        //они оба положительные
        if (this->number.size() < a.number.size()) {
            return false;
        }
        else if (this->number.size() > a.number.size()) {
            return true;
        }
        else {
            for (int i = this->number.size() - 1; i >= 0; i--) {
                if (this->number[i] > a.number[i]) {
                    return true;
                }
                if (this->number[i] < a.number[i]) {
                    return false;
                }
            }
            return true;
        }
    }
private:
    int base = 10;
    int one = 1;
    vector<int> number;
};
