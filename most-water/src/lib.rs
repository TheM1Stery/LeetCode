struct Solution;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut area = 0;
        let mut l = 0;
        let mut r = height.len() - 1;
        while l < r {
            if height[l] <= height[r] {
                area = area.max(height[l] * (r - l) as i32);
                l += 1;
            } else {
                area = area.max(height[r] * (r - l) as i32);
                r -= 1;
            }
        }

        area
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn setup_case(input: Vec<i32>, expected: i32) {
        let actual = Solution::max_area(input);

        assert_eq!(actual, expected)
    }

    #[test]
    fn first() {
        setup_case(vec![1, 8, 6, 2, 5, 4, 8, 3, 7], 49)
    }

    #[test]
    fn second() {
        setup_case(vec![1, 1], 1)
    }
}
