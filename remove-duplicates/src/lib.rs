struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut count = 1;
        let mut i = 0;
        let len = nums.len();

        while i < len {
            if i != 0 && nums[i] != nums[i - 1] {
                nums[count as usize] = nums[i];
                count += 1;
            }
            i += 1;
        }

        count
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first_case() {
        let mut vec = vec![1, 1, 2];
        let expected_vec = vec![1, 2, 3];
        let expected = (2, &expected_vec[..2]);
        let actual = (Solution::remove_duplicates(&mut vec), &vec[..2]);

        println!("{vec:?} {expected_vec:?}");

        assert_eq!(actual, expected);
    }

    #[test]
    fn second_case() {
        let mut vec = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
        let expected_vec = vec![0, 1, 2, 3, 4];
        let expected = (5, &expected_vec[..5]);
        let actual = (Solution::remove_duplicates(&mut vec), &vec[..5]);

        println!("{vec:?} {expected_vec:?}");

        assert_eq!(actual, expected);
    }
}
