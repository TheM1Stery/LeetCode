struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut buy = 0;
        let mut profit = 0;
        for sell in 1..prices.len() {
            let diff = prices[sell] - prices[buy];
            if diff < 0 {
                buy = sell;
                continue;
            }
            if profit < diff {
                profit = diff;
            }
        }

        profit
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first_case() {
        let input = vec![7, 1, 5, 3, 6, 4];
        let expected = 5;
        let actual = Solution::max_profit(input);

        assert_eq!(actual, expected)
    }

    #[test]
    fn second_case() {
        let input = vec![7, 6, 4, 3, 1];
        let expected = 0;
        let actual = Solution::max_profit(input);

        assert_eq!(actual, expected)
    }

    #[test]
    fn third_case() {
        let input = vec![2, 4, 1];
        let expected = 2;
        let actual = Solution::max_profit(input);

        assert_eq!(actual, expected)
    }

    #[test]
    fn fourth_case() {
        let input = vec![2, 1, 2, 1, 0, 1, 2];
        let expected = 2;
        let actual = Solution::max_profit(input);

        assert_eq!(actual, expected)
    }
}
